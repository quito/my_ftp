/*
** init_socket.c for  in /home/quito/projet_tmp/my_ftp/srv
** 
** Made by pierre collet
** Login   <collet_p@epitech.net>
** 
** Started on  Mon Apr  2 13:52:44 2012 pierre collet
** Last update Mon Apr  2 13:52:44 2012 pierre collet
*/

#include <stdio.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include "server.h"

int			init_addr(t_info *info)
{
  int			err;

  info->sin.sin_family = AF_INET;
  info->sin.sin_port = htons(info->port);
  info->sin.sin_addr.s_addr = INADDR_ANY;
  err = bind(info->socket,
	     (const struct sockaddr *)(&(info->sin)),
	     sizeof(info->sin));
  if (err == -1)
    {
      perror("Bind");
      return (0);
    }
  return (1);
}

int			init_socket(t_info *info)
{
  struct protoent	*pe;
  
  if ((pe = getprotobyname("TCP")) == NULL)
    {
      fprintf(stderr, "Cannot perform a getprotobyname\n");
      return (0);
    }
  if ((info->socket = socket(AF_INET, SOCK_STREAM, pe->p_proto)) == -1)
    {
      perror("socket");
      return (0);
    }
  if (!init_addr(info))
    return (0);
  if (listen(info->socket, 100) == -1)
    {
      perror("listen");
      return (0);
    }    
  return (1);
}

  
