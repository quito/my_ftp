/*
** init_serv.c for  in /home/collet_p/projet_tmp/my_ftp/srv
** 
** Made by pierre collet
** Login   <collet_p@epitech.net>
** 
** Started on  Mon Mar 26 11:42:14 2012 pierre collet
** Last update Mon Mar 26 11:42:14 2012 pierre collet
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "server.h"

static int	get_opt(t_info *info, char *port)
{
  int		p;

  p = atoi(port);
  if (p > 0 && p < 0xFFFF)
    {
      info->port = p;
      return (1);
    }
  fprintf(stderr, "Error bad port try between 1 and %d\n", 0xFFFF);
  return (0);
}

int	init_serv(t_info *info, char **av)
{
  if (!get_opt(info, av[1]))
    return (0);
  info->accept_connections = 1;
  info->pid_list = NULL;
  manage_signal();
  return (1);
}
