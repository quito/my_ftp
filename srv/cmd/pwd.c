/*
** pwd.c for  in /home/quito/projet_tmp/my_ftp/srv
** 
** Made by pierre collet
** Login   <collet_p@epitech.net>
** 
** Started on  Thu Apr  5 13:07:51 2012 pierre collet
** Last update Thu Apr  5 13:07:51 2012 pierre collet
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "server.h"

int		cmd_pwd(t_info *info, char *str)
{
  char		buffer[290];

  (void)str;
  snprintf(buffer, sizeof(buffer), "\"%s\" is current directory.", info->cur_path);
  send_answer(info, buffer, 257);
  return (1);
}
