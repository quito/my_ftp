/*
** get_cmd_arg.c for  in /home/quito/projet_tmp/my_ftp/srv
** 
** Made by pierre collet
** Login   <collet_p@epitech.net>
** 
** Started on  Wed Apr  4 02:26:35 2012 pierre collet
** Last update Wed Apr  4 02:26:35 2012 pierre collet
*/

#include <stdlib.h>
#include "server.h"

void	delete_endline(char *str)
{
  int	j;

  j = 0;
  while (str[j])
    {
      if (str[j] == '\n' || str[j] == '\r')
	str[j] = '\0';
      j++;
    }  
}

char	*get_cmd_arg(char *str)
{
  int	i;

  i = 0;
  if (!str)
    return (NULL);
  while (str[i] && str[i] != ' ')
    i++;
  if (str[i] == ' ')
    return (&(str[i + 1]));
  return (NULL);
}
