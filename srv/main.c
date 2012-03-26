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
#include "server.h"

static void	print_usage(char *str)
{
  fprintf(stderr, "Usage : %s port\n", str);
}

int		main(int ac, char **av)
{
  t_info	info;

  if (ac == 2)
    {
      if (init_serv(&info, av))
	{
	  return (EXIT_SUCCESS);
	}
    }
  else
    print_usage(av[0]);
  return (EXIT_FAILURE);
}
