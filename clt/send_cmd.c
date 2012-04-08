/*
** send_cmd.c for  in /home/quito/projet_tmp/my_ftp/clt
** 
** Made by pierre collet
** Login   <collet_p@epitech.net>
** 
** Started on  Fri Apr  6 18:54:10 2012 pierre collet
** Last update Fri Apr  6 18:54:10 2012 pierre collet
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "client.h"

int		send_cmd(t_info *info, char *str, char *arg)
{
  char		buffer[256];

  if (arg)
    snprintf(buffer, 256, "%s %s\r\n", str, arg);
  else
    snprintf(buffer, 256, "%s\r\n", str);
  write_secure(info->socket, buffer, strlen(buffer), info);
  return (1);
}
