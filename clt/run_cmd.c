/*
** run_cmd.c for  in /home/quito/projet_tmp/my_ftp/clt
** 
** Made by pierre collet
** Login   <collet_p@epitech.net>
** 
** Started on  Sat Apr  7 21:56:20 2012 pierre collet
** Last update Sat Apr  7 21:56:20 2012 pierre collet
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "client.h"

t_cmd_func	g_cmd_tab[] =
  {
    {"ls", cmd_ls},
    {"cd", cmd_cd},
    {"get", cmd_get},
    {"put", cmd_put},
    {"pwd", cmd_pwd},
    {"quit", cmd_exit},
  };

int		run_cmd(t_info *info, t_cmd *cmd)
{
  int		i;
  int		max;

  if (!cmd || !(cmd->cmd))
    return (0);
  i = 0;
  max = sizeof(g_cmd_tab) / sizeof(t_cmd_func);
  while (i < max)
    {
      if (strcmp(cmd->cmd, g_cmd_tab[i].name) == 0 &&
	  g_cmd_tab[i].func != NULL)
	return ((g_cmd_tab[i].func)(info, cmd));
      i++;
    }
  fprintf(stderr, "Command not found.\n");
  return (0);
}
