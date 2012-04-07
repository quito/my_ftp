/*
** cdup.c for  in /home/quito/projet_tmp/my_ftp/srv
** 
** Made by pierre collet
** Login   <collet_p@epitech.net>
** 
** Started on  Sat Apr  7 00:07:35 2012 pierre collet
** Last update Sat Apr  7 00:07:35 2012 pierre collet
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "server.h"

int		cmd_cdup(t_info *info, char *str)
{
  (void)str;
  my_chdir("../", info);
  send_answer(info, "CDUP command successful", 250);
  return (1);
}
