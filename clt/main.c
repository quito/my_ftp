/*
** main.c for  in /home/collet_p/projet_tmp/my_ftp
** 
** Made by pierre collet
** Login   <collet_p@epitech.net>
** 
** Started on  Mon Mar 26 11:27:59 2012 pierre collet
** Last update Mon Mar 26 11:27:59 2012 pierre collet
*/

#include <stdlib.h>
#include <stdio.h>
#include "client.h"

static void	print_usage(char *str)
{
  fprintf(stderr, "Usage : %s server_addr port\n", str);
  fprintf(stderr, "\n\t server_addr :\t IP adress of the ftp server\n");
  fprintf(stderr, "\t port :\t port of the ftp server\n");
}

int		main(int ac, char **av)
{
  t_info	info;

  if (ac == 3)
    {
      if (init_client(&info, av) && init_socket(&info))
	{
	  
	  return (EXIT_SUCCESS);
	}
    }
  else
    print_usage(av[0]);
  return (EXIT_FAILURE);
}
