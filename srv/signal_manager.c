/*
** signal_manager.c for  in /home/quito/projet_tmp/my_ftp/srv
** 
** Made by pierre collet
** Login   <collet_p@epitech.net>
** 
** Started on  Mon Apr  2 17:34:59 2012 pierre collet
** Last update Mon Apr  2 17:34:59 2012 pierre collet
*/

#include <signal.h>
#include <stdio.h>
#include "server.h"

extern t_info	g_info;

void		manage_sig(int sig)
{
  (void)sig;
  printf("[\033[31;1m-\033[0m] Killing server...");
  g_info.accept_connections = 0;
}

void		manage_signal(void)
{
  signal(SIGINT, manage_sig);
}
