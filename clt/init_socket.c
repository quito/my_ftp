/*
** init_socket.c for  in /home/collet_p/projet_tmp/my_ftp/clt
** 
** Made by pierre collet
** Login   <collet_p@epitech.net>
** 
** Started on  Mon Mar 26 14:48:50 2012 pierre collet
** Last update Mon Mar 26 14:48:50 2012 pierre collet
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include "client.h"

int	init_socket(t_info *info)
{
  info->socket = socket(AF_INET, SOCK_STREAM, 0);
  if (info->socket == -1)
    {
      fprintf(stderr, "Error : Cannot open a socket\n");
      return (0);
    }
  info->sock_in.sin_addr.s_addr = inet_addr(info->serv_ip);
  info->sock_in.sin_family = AF_INET;
  info->sock_in.sin_port = htons(info->port);
  printf("[*] Connection... Waiting for host...\n");
  if (connect(info->socket,
	      (struct sockaddr*)(&(info->sock_in)),
	      sizeof (info->sock_in)) == -1)
    {
      fprintf(stderr, "[\033[31;1m-\033[0m] Error : Connection time out\n");
      return (0);
    }
  printf("[\033[32;1m+\033[0m] Connected :)\n");
  return (1);
}
