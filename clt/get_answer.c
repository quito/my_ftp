/*
** get_answer.c for  in /home/quito/projet_tmp/my_ftp/clt
** 
** Made by pierre collet
** Login   <collet_p@epitech.net>
** 
** Started on  Fri Apr  6 19:09:28 2012 pierre collet
** Last update Fri Apr  6 19:09:28 2012 pierre collet
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "client.h"

static char	*read_secure(t_info *info)
{
  char		buffer[512];
  int		ret;

  if (!info->keep_connected)
    return (NULL);
  if ((ret = read(info->socket, buffer, sizeof(buffer) - 1)) <= 0)
    {
      info->keep_connected = 0;
      return (NULL);
    }
  buffer[ret] = '\0';
  return (strndup(buffer, sizeof(buffer)));
}

int	get_answer(t_info *info, t_rep *rep)
{
  char	*str;

  if (rep)
    {
      if (!(str = read_secure(info)))
	return (0);
      epur_str_r(str);
      if (write(1, str, strlen(str)) == -1)
	  write(2, "Cannot write on stdout\n", 23);
      rep->code = get_num_answer(str);
      rep->msg = get_arg_answer(str);
      free(str);
      return (1);
    }
  return (0);
}
