/*
** cmd_put.c for  in /home/quito/projet_tmp/my_ftp/clt
** 
** Made by pierre collet
** Login   <collet_p@epitech.net>
** 
** Started on  Sat Apr  7 22:34:04 2012 pierre collet
** Last update Sat Apr  7 22:34:04 2012 pierre collet
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

  if ((fd = open(str, O_RDONLY)) == -1)
    fprintf(stderr, "Cannot open file %s.\n", str);
  return (fd);
}

int		cmd_put(t_info *info, t_cmd *cmd)
{
  t_rep		rep;
  int		fd;

  if ((fd = open_file(cmd->arg)) == -1 || !send_cmd(info, "TYPE", "I") ||
     !get_answer(info, &rep) || !get_pasv(info))
    return (0);
  send_cmd(info, "STOR", cmd->arg);
  if (connect_dtp(info->dtp) && get_answer(info, &rep) &&
      rep.code == 150 && read_data(info, fd, info->dtp->socket))
    {
      close_dtp(info);
      if (close(fd) != -1 &&
	  get_answer(info, &rep) && IS_200(rep.code))
	return (1);
      return (0);
    }
  close(fd);
  close_dtp(info);
  return (1);
}
