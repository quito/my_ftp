/*
** cut_cmd.c for  in /home/quito/projet_tmp/my_ftp/clt
** 
** Made by pierre collet
** Login   <collet_p@epitech.net>
** 
** Started on  Sat Apr  7 21:19:52 2012 pierre collet
** Last update Sat Apr  7 21:19:52 2012 pierre collet
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "client.h"

char	*get_cmd_arg(char *str)
{
  int	i;

  i = 0;
  while (str[i] && str[i] == ' ')
    i++;
  while (str[i] && str[i] != ' ')
    i++;
  while (str[i] && str[i] == ' ')
    i++;
  if (str[i])
    return (strdup(&(str[i])));
  return (NULL);
}

char	*get_cmd(char *str)
{
  int	i;
  int	j;

  if (strlen(str) == 0)
    return (NULL);
  i = 0;
  while (str[i] && str[i] == ' ')
    i++;
  j = i;
  while (str[j] && str[j] != ' ')
    j++;
  if (str[j] == ' ')
    return (strndup(&(str[i]), j - i));
  else
    return (strdup(&(str[i])));
}
