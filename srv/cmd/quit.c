/*
** quit.c for  in /home/quito/projet_tmp/my_ftp/srv
** 
** Made by pierre collet
** Login   <collet_p@epitech.net>
** 
** Started on  Sat Apr  7 13:53:45 2012 pierre collet
** Last update Sat Apr  7 13:53:45 2012 pierre collet
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "server.h"

int		cmd_quit(t_info *info, char *str)
{
  (void)str;
  info->keep_connected = 0;
  send_answer(info, "Goodbye.", 221);
  return (1);
}
