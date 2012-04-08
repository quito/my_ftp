/*
** get_pasv.c for  in /home/quito/projet_tmp/my_ftp/clt
** 
** Made by pierre collet
** Login   <collet_p@epitech.net>
** 
** Started on  Sun Apr  8 00:57:56 2012 pierre collet
** Last update Sun Apr  8 00:57:56 2012 pierre collet
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "client.h"

static char	*get_ip_str(char *str)
{
  int		i;

  i = 0;
  if (str)
    {
      while (str[i] && (str[i] < '0' || str[i] > '9'))
	i++;
      if (str[i] >= '0' || str[i] <= '9')
	return (&(str[i]));
    }
  return (NULL);
}

static void	get_ip_value(char *str, char *buf)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  while (str[i] && j < 4)
    {
      if (str[i] == ',')
	{
	  j++;
	  if (j < 4)
	    buf[i] = '.';
	}
      else
	buf[i] = str[i];
      i++;
    }
}

static int		get_port_value(char *str)
{
  int			i;
  int			j;
  unsigned short	sum;

  j = 0;
  sum = 0;
  while (j < 6)
    {
      if (j > 3)
	{
	  sum += atoi(&(str[i]));
	  if (j == 4)
	    sum = sum << 8;
	}
      while (str[i] && str[i] != ',')
	i++;
      if (str[i] == ',')
	i++;
      j++;
    }
  str[i] = '\0';
  return (sum);
}

int		get_pasv(t_info *info)
{
  t_rep		rep;
  char		*ip_str;
  char		ip[16];
  unsigned int	port;

  memset(ip, 0, sizeof(ip));
  if (!send_cmd(info, "PASV", NULL) || !get_answer(info, &rep))
    return (0);
  if (!(ip_str = get_ip_str(rep.msg)))
    return (0);
  get_ip_value(ip_str, ip);
  port = get_port_value(ip_str);
  return (create_dtp(info, ip, port));
}
