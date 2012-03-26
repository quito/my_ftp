/*
** init_client.c for  in /home/collet_p/projet_tmp/my_ftp/clt
** 
** Made by pierre collet
** Login   <collet_p@epitech.net>
** 
** Started on  Mon Mar 26 11:49:16 2012 pierre collet
** Last update Mon Mar 26 11:49:16 2012 pierre collet
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "client.h"

static int	check_ip(char *str)
{
  int		i;
  int		count_p;
  int		count_nb;

  if (!(str[0] <= '9' && str[0] > '0'))
    return (0);
  while (str[i])
    {
      if (str[0] <= '9' && str[0] > '0')
	count_nb++;
      if (count_nb > 3)
	return (0);
      if (str[0] == '.')
	count_nb = 0;
      if (str[0] == '.')
	count_p++;
      if (count_p > 3)
	return (0);
      i++;
    }
  return (1);
}

static int	get_opt(t_info *info, char *ip, char *port)
{
  int		p;

  p = atoi(port);
  if (p < 0 || p > 0xFFFF)
    {
      fprintf(stderr, "Error : Bad port number\n");
      return (0);
    }
  info->port = p;
  if (check_ip(ip))
    return (1);
  fprintf(stderr, "Error : Bad ip. Try something like 192.168.1.12\n");
  return (0);
}

int	init_client(t_info *info, char **av)
{
  if (!get_opt(info, av[1], av[2]))
    return (0);
  return (1);
}
