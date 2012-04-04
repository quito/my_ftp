/*
** noop.c for  in /home/quito/projet_tmp/my_ftp/srv
** 
** Made by pierre collet
** Login   <collet_p@epitech.net>
** 
** Started on  Wed Apr  4 01:54:11 2012 pierre collet
** Last update Wed Apr  4 01:54:11 2012 pierre collet
*/

#include <stdlib.h>
#include <unistd.h>
#include "server.h"

int		cmd_noop(t_info *info, char *str)
{
  (void)str;
  if (write_secure(info->csock, "NOOP command successful", 200, info) > 0)
    return (1);
  return (0);
}
