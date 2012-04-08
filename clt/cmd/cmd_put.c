/*
** cmd_put.c for  in /home/quito/projet_tmp/my_ftp/clt
** 
** Made by pierre collet
** Login   <collet_p@epitech.net>
** 
** Started on  Sat Apr  7 22:34:04 2012 pierre collet
** Last update Sat Apr  7 22:34:04 2012 pierre collet
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "client.h"

int		cmd_put(t_info *info, t_cmd *cmd)
{
  (void)cmd;
  printf("Exiting...\n");
  info->keep_connected = 0;
  return (1);
}
