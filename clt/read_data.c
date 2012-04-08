/*
** read_data.c for  in /home/quito/projet_tmp/my_ftp/clt
** 
** Made by pierre collet
** Login   <collet_p@epitech.net>
** 
** Started on  Sun Apr  8 02:05:53 2012 pierre collet
** Last update Sun Apr  8 02:05:53 2012 pierre collet
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "client.h"

int		read_data(t_info *info, int fd_in, int fd_out)
{
  char		buffer[512];
  int		ret;

  (void)info;
  while ((ret = read(fd_in, buffer, sizeof(buffer))) > 0)
    {
      if (write(fd_out, buffer, ret) == -1)
	{
	  fprintf(stderr, "Cannot write on fd %d\n", fd_out);
	  return (0);
	}
    }
  return (1);
}
