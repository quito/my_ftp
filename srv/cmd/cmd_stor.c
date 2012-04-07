/*
** cmd_stor.c for  in /home/quito/projet_tmp/my_ftp/srv
** 
** Made by pierre collet
** Login   <collet_p@epitech.net>
** 
** Started on  Sat Apr  7 13:46:33 2012 pierre collet
** Last update Sat Apr  7 13:46:33 2012 pierre collet
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "server.h"

static int	get_file(t_info *info, int fd, char *arg)
{
  char		buf[256];
  int		ret;
  char		buffer[512];
  int		b;

  b = 1;
  if (!accept_pasv_connection(info))
    return (0);
  snprintf(buf, sizeof(buf), "Opening ASCII mode data connection for %s", arg);
  send_answer(info, buf, 150);
  while (b > 0 && (ret = read(info->dtp->c_sock, buffer, 1)) > 0)
    {
      b = write(fd, buffer, ret);
    }
  send_answer(info, "Transfer complete.", 226);
  return (1);
}

int		cmd_stor(t_info *info, char *str)
{
  char		*arg;
  int		fd;

  if ((arg = get_cmd_arg(str)) == NULL)
    {
      send_answer(info, "Missing Argument.", 501);
      return (0);
    }
  if (!(info->dtp))
    {
      send_answer(info, "DTP not opened", 550);
      return (0);
    }
  printf("argument:%s\n", arg);
  if ((fd = open(arg, O_WRONLY | O_CREAT | O_TRUNC,
		 S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) == -1)
    {
      send_answer(info, "Cannot create file", 550);
      return (0);
    }
  get_file(info, fd, arg);
  close_dtp(info);
  close(fd);
  return (1);
}
