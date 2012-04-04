/*
** client_manager.c for  in /home/quito/projet_tmp/my_ftp/srv
** 
** Made by pierre collet
** Login   <collet_p@epitech.net>
** 
** Started on  Mon Apr  2 17:15:10 2012 pierre collet
** Last update Mon Apr  2 17:15:10 2012 pierre collet
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "server.h"

t_cmd		g_cmd_tab[] =
  {
    {"USER", cmd_user, 4},
    {"PASS", NULL, 4},
    {"CWD", NULL, 1},
    {"PWD", NULL, 1},
    {"CDUP", NULL, 1},
    {"QUIT", NULL, 1},
    {"REIN", NULL, 2},
    {"TYPE", NULL, 1},
    {"PASV", NULL, 1},
    {"MODE", NULL, 1},
    {"RNFR", NULL, 3},
    {"RNTO", NULL, 3},
    {"ABOR", NULL, 1},
    {"DELE", NULL, 1},
    {"RMD", NULL, 1},
    {"MKD", NULL, 1},
    {"LIST", NULL, 2},
    {"NLST", NULL, 2},
    {"SYST", NULL, 1},
    {"HELP", NULL, 1},
    {"NOOP", cmd_noop, 1}
  };

static int	write_welcome_message(t_info *info)
{
  return (write_secure(info->csock,
		       "220 " WELCOME_MSG "\r\n",
		       strlen("220" WELCOME_MSG "\r\n"),
		       info));
}

static t_cmd	*find_function(char *str)
{
  unsigned int	i;
  char		buffer[32];

  i = 0;
  memset(buffer, 0, 32);
  if (str)
    {
      while (i < sizeof(g_cmd_tab) / sizeof(t_cmd))
	{
	  strncpy(buffer, str, strcspn(str, " ") > 31 ? 31 : strcspn(str, " "));
	  if (strcasecmp(buffer, g_cmd_tab[i].name) == 0)
	    return (&(g_cmd_tab[i]));
	  i++;
	}
    }
  return (NULL);
}

int		client_manager(t_info *info)
{
  char		buffer[BUFF_SIZE + 1];
  t_cmd		*ptr;

  memset(buffer, 0, sizeof(buffer));
  write_welcome_message(info);
  while (info->keep_connected && read(info->csock, buffer, BUFF_SIZE) > 0)
    {
      printf("%s\n", buffer);
      if ((ptr = find_function(buffer)) == NULL)
	send_answer(info, "command unrecognized.", 500);
      else
	ptr->ptr(info, buffer);
      memset(buffer, 0, sizeof(buffer));
    }
  return (1);
}
