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
#include <string.h>
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

  memset(info, 0, sizeof(*info));
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
  if (listen(info->socket, 1) == -1)
    {
      perror("listen");
      return (0);
    }
  return (1);
}

static int              build_answer(int fd, int sock_c, char *buf)
{
  socklen_t             l;
  unsigned short        port;
  char                  *ip;
  struct sockaddr_in    sp;
  struct sockaddr_in    si;

  l = sizeof(struct sockaddr_in);
  if (getsockname(sock_c, (struct sockaddr *)&sp, &l) < 0)
    {
      perror("getsockname");
      return (0);
    }
  port = ntohs(sp.sin_port);
  if (getsockname(fd, (struct sockaddr *)&si, &l) < 0)
    {
      perror("getsockname");
      return (0);
    }
  ip = (char *)&si.sin_addr;
  snprintf(buf, 1024, "%d,%d,%d,%d,%d,%d",
	   ip[0] & 0xff, ip[1] & 0xff, ip[2] & 0xff, ip[3] & 0xff,
	   (port >> 8) & 0xff, port & 0xff);
  return (0);
}

int		cmd_pasv(t_info *info, char *str)
{
  char		buffer[256];

  (void)str;
  if ((info->dtp = malloc(sizeof(*(info->dtp)))) == NULL ||
      !dtp_init_socket(info->dtp))
    {
      send_answer(info, "Cannot open a connection", 530);
      free(info->dtp);
      return (0);
    }
  build_answer(info->csock, info->dtp->socket, &(buffer[0]));
  send_answer(info, buffer, 227);
  return (1);
}
