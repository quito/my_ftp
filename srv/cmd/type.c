/*
** type.c for  in /home/quito/projet_tmp/my_ftp/srv
** 
** Made by pierre collet
** Login   <collet_p@epitech.net>
** 
** Started on  Thu Apr  5 15:43:55 2012 pierre collet
** Last update Thu Apr  5 15:43:55 2012 pierre collet
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "server.h"

int		cmd_type(t_info *info, char *str)
{
  char		*arg;

  arg = get_cmd_arg(str);
  if (arg == NULL)
    {
      send_answer(info, "Command TYPE need an argument", 501);
      return (0);
    }
  if (strcmp(arg, "I") != 0)
    {
      send_answer(info, "Argument not implemented for TYPE ", 504);
      return (0);      
    }
  send_answer(info, "Type set to I", 200);
  return (1);
}
