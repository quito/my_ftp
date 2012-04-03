/*
** write_secure.c for  in /home/quito/projet_tmp/my_ftp/srv
** 
** Made by pierre collet
** Login   <collet_p@epitech.net>
** 
** Started on  Tue Apr  3 10:31:45 2012 pierre collet
** Last update Tue Apr  3 10:31:45 2012 pierre collet
*/

#include <unistd.h>
#include <stdio.h>
#include "server.h"

int	write_secure(int fd, char *str, unsigned int size)
{
  int	ret;

  ret = write(fd, str, size);
  if (ret == 0)
    fprintf(stderr, "Disconnected from client\n");
  else if (ret < 0)
    perror("write");
  return (ret);
}
