/*
** cmd_get.c for  in /home/quito/projet_tmp/my_ftp/clt
** 
** Made by pierre collet
** Login   <collet_p@epitech.net>
** 
** Started on  Sat Apr  7 22:33:49 2012 pierre collet
** Last update Sat Apr  7 22:33:49 2012 pierre collet
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "client.h"

static int	open_file(char *str)
{
  int		fd;

  if ((fd = open(str, O_WRONLY | O_CREAT | O_TRUNC,
		 S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) == -1)
    fprintf(stderr, "Cannot open file %s.\n", str);
  return (fd);
}

int		cmd_get(t_info *info, t_cmd *cmd)
{
  t_rep		rep;
  int		fd;

  if(!get_pasv(info) || (fd = open_file(cmd->arg)) == -1)
    return (0);
  if (!send_cmd(info, "TYPE", "I") || !get_answer(info, &rep))
    return (0);
  send_cmd(info, "RETR", cmd->arg);
  if (get_answer(info, &rep) && rep.code == 150 &&
      connect_dtp(info->dtp) && read_data(info, info->dtp->socket, fd))
    {
      if (get_answer(info, &rep) && IS_200(rep.code))
	{
	  close_dtp(info);
	  return (1);
	}
      close_dtp(info);
      return (0);
    }
  close(fd);
  close_dtp(info);
  return (1);
}
