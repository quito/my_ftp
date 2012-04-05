/*
** pasv.c for  in /home/quito/projet_tmp/my_ftp/srv
** 
** Made by pierre collet
** Login   <collet_p@epitech.net>
** 
** Started on  Thu Apr  5 16:35:54 2012 pierre collet
** Last update Thu Apr  5 16:35:54 2012 pierre collet
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include "server.h"

static int		dtp_init_addr(t_pasv_dtp *info)
{
  int			err;

  info->sin.sin_family = AF_INET;
  info->sin.sin_port = htons(0);
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

int			dtp_init_socket(t_pasv_dtp *info)
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
  if (!dtp_init_addr(info))
    return (0);
  if (listen(info->socket, 100) == -1)
    {
      perror("listen");
      return (0);
    }    
  return (1);
}

int		cmd_pasv(t_info *info, char *str)
{
  (void)str;
  if ((info->dtp = malloc(sizeof(*(info->dtp)))) == NULL ||
      !dtp_init_socket(info->dtp))
    {
      send_answer(info, "Cannot open a connection", 530);
      return (0);
    }
  /* construction et envoi de la reponse */
  return (1);
}
