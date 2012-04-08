/*
** init_signal.c for  in /home/collet_p//projet_tmp/my_ftp/clt
** 
** Made by pierre collet
** Login   <collet_p@epitech.net>
** 
** Started on  Sun Apr  8 19:14:54 2012 pierre collet
** Last update Sun Apr  8 19:14:54 2012 pierre collet
*/

#include <stdio.h>
#include <signal.h>
#include "client.h"

void		useless(int sig)
{
  (void)sig;
  fprintf(stderr, "[-] Connection error\n");
}

void		manage_signal()
{
  signal(SIGPIPE, useless);
}
