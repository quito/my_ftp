/*
** run_client.c for  in /home/quito/projet_tmp/my_ftp/clt
** 
** Made by pierre collet
** Login   <collet_p@epitech.net>
** 
** Started on  Mon Apr  2 20:28:16 2012 pierre collet
** Last update Mon Apr  2 20:28:16 2012 pierre collet
*/

#include <stdlib.h>
#include <stdio.h>
#include "client.h"

static int	open_session()
{
}

int		run_client(t_info *info)
{
  printf("[*] Waiting for Welcome message\n");
  while (info->keep_connected)
    {
    }
  printf("[*] Disconnected from server\n");
  return (1);
}
