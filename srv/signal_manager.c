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
#include <unistd.h>
#include <sys/types.h>
#include "server.h"

extern t_info	g_info;

static void	kill_son(t_list *list)
{
  long int		pid;

  while (list)
    {
      pid = (long int)list->data;
      kill(pid, SIGINT);
      list = list->next;
    }
}

void		manage_sig(int sig)
{
  (void)sig;
  printf("[\033[31;1m-\033[0m] Killing server...\n");
  g_info.accept_connections = 0;
  g_info.keep_connected = 0;
  close(g_info.csock);
  kill_son(g_info.pid_list);
  manage_signal();
}

void		manage_signal(void)
{
  signal(SIGINT, manage_sig);
}
