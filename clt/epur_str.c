/*
** epur_str.c for  in /home/quito/projet_tmp/my_ftp/clt
** 
** Made by pierre collet
** Login   <collet_p@epitech.net>
** 
** Started on  Sat Apr  7 19:39:00 2012 pierre collet
** Last update Sat Apr  7 19:39:00 2012 pierre collet
*/

#include <stdlib.h>
#include "client.h"

void		epur_str_r(char *str)
{
  int		i;

  i = 0;
  if (str)
    {
      while (str[i])
	{
	  if (str[i] == '\r')
	    str[i] = '\0';
	  i++;
	}
    }
}

void		epur_str(char *str)
{
  int		i;

  i = 0;
  if (str)
    {
      while (str[i])
	{
	  if (str[i] == '\n' || str[i] == '\r')
	    str[i] = '\0';
	  i++;
	}
    }
}
