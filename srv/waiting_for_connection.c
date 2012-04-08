/*
** waiting_for_connection.c for  in /home/quito/projet_tmp/my_ftp/srv
** 
** Made by pierre collet
** Login   <collet_p@epitech.net>
** 
** Started on  Mon Apr  2 16:09:25 2012 pierre collet
** Last update Mon Apr  2 16:09:25 2012 pierre collet
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "server.h"

static int	manage_client(t_info *info)
{
  long int	pid;

  pid = fork();
  if (pid == -1)
    {
      close(info->csock);
      return (0);
    }
  if (pid == 0)
    {
      if (client_manager(info))
	exit(EXIT_SUCCESS);
      exit(EXIT_FAILURE);
    }
  else
    info->pid_list = push_back_list(info->pid_list, (void*)pid);
  return (1);
}

int		waiting_for_connection(t_info *info)
{
  int		b;
  unsigned int	size;

  b = 1;
  while (info->accept_connections)
    {
      size = sizeof(info->sin_client);
      info->csock = accept(info->socket,
			   (struct sockaddr *)(&(info->sin_client)),
			   &size);
      if (info->csock == -1)
	{
	  b = 0;
	  info->accept_connections = 0;
	}
      else if (manage_client(info) == 0)
	info->accept_connections = 0;
      close(info->csock);
    }
  waiting_for_pid(info->pid_list);
  return (b);
}
