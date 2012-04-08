/*
** prompt.c for  in /home/quito/projet_tmp/my_ftp/clt
** 
** Made by pierre collet
** Login   <collet_p@epitech.net>
** 
** Started on  Sat Apr  7 21:12:38 2012 pierre collet
** Last update Sat Apr  7 21:12:38 2012 pierre collet
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "client.h"

int		prompt(t_cmd *cmd)
{
  char		buffer[300];

  memset(buffer, 0, sizeof(buffer));
  if (cmd)
    {
      if (write(1, "cmd$> ", 6) == -1)
	return (0);
      if (read(0, buffer, sizeof(buffer) - 1) <= 0)
	return (0);
      epur_str(buffer);
      cmd->cmd = get_cmd(buffer);
      cmd->arg = get_cmd_arg(buffer);
      return (1);
    }
  return (0);
}
