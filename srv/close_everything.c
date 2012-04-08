/*
** close_everything.c for  in /home/quito/projet_tmp/my_ftp/srv
** 
** Made by pierre collet
** Login   <collet_p@epitech.net>
** 
** Started on  Sat Apr  7 20:21:25 2012 pierre collet
** Last update Sat Apr  7 20:21:25 2012 pierre collet
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "server.h"

void	close_everything(t_info *info)
{
  if (info)
    {
      if (info->dtp)
	{
	  info->dtp->accept_connections = 0;
	  close(info->dtp->socket);
	  close(info->dtp->c_sock);
	  free(info->dtp);
	  info->dtp = NULL;
	}
      info->keep_connected = 0;
      info->accept_connections = 0;
      close(info->socket);
      close(info->csock);
      freelist(info->users_list);
    }
}
