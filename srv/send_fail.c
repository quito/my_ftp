/*
** send_fail.c for  in /home/quito/projet_tmp/my_ftp/srv
** 
** Made by pierre collet
** Login   <collet_p@epitech.net>
** 
** Started on  Tue Apr  3 13:20:17 2012 pierre collet
** Last update Tue Apr  3 13:20:17 2012 pierre collet
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "server.h"

int	send_fail(t_info *info, char *str, int num)
{
  char	buff[257];

  memset(buff, 0, sizeof(buff));
  if (str)
    {    
      snprintf(buff, 256, "%d %s\n", num, str);
      fprintf(stderr, "%d %s\n", num, str);
    }
  else
    snprintf(buff, 256, "%d\n", num);
  return (write_secure(info->csock, buff, strlen(buff)));
}
