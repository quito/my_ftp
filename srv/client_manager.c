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

t_cmd		g_cmd_tab [] =
  {
    {"USER", NULL},
    {"PASS", NULL},
    {"CWD", NULL},
    {"PWD", NULL},
    {"CDUP", NULL},
    {"QUIT", NULL},
    {"REIN", NULL},
    {"TYPE", NULL},
    {"PASV", NULL},
    {"MODE", NULL},
    {"RNFR", NULL},
    {"RNTO", NULL},
    {"ABOR", NULL},
    {"DELE", NULL},
    {"RMD", NULL},
    {"MKD", NULL},
    {"LIST", NULL},
    {"NLST", NULL},
    {"SYST", NULL},
    {"HELP", NULL},
    {"NOOP", NULL}
  };

static int	write_welcome_message(t_info *info)
{
  return (write_secure(info->csock,
		       "220 " WELCOME_MSG "\n",
		       strlen ("220" WELCOME_MSG "\n")));
}

int		client_manager(t_info *info)
{
  char		buffer[BUFF_SIZE + 1];

  memset(buffer, 0, sizeof(buffer));
  write_welcome_message(info);
  while (read(info->csock, buffer, BUFF_SIZE))
    {
      
    }
  return (1);
}
