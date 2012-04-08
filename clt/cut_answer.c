/*
** cut_answer.c for  in /home/quito/projet_tmp/my_ftp/clt
** 
** Made by pierre collet
** Login   <collet_p@epitech.net>
** 
** Started on  Fri Apr  6 19:02:57 2012 pierre collet
** Last update Fri Apr  6 19:02:57 2012 pierre collet
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "client.h"

char	*get_arg_answer(char *str)
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

int	get_num_answer(char *str)
{
  int	i;

  i = 0;
  while (str[i] && str[i] == ' ')
    i++;
  return (atoi(&(str[i])));
}
