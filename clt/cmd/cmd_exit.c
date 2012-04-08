/*
** cmd_exit.c for  in /home/quito/projet_tmp/my_ftp/clt
** 
** Made by pierre collet
** Login   <collet_p@epitech.net>
** 
** Started on  Sat Apr  7 22:27:04 2012 pierre collet
** Last update Sat Apr  7 22:27:04 2012 pierre collet
*/

#include <stdio.h>
#include "client.h"

int		cmd_exit(t_info *info, t_cmd *cmd)
{
  (void)cmd;
  printf("Exiting...\n");
  info->keep_connected = 0;
  return (1);
}
