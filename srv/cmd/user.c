/*
** user.c for  in /home/quito/projet_tmp/my_ftp/srv
** 
** Made by pierre collet
** Login   <collet_p@epitech.net>
** 
** Started on  Wed Apr  4 02:26:14 2012 pierre collet
** Last update Wed Apr  4 02:26:14 2012 pierre collet
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "server.h"

static int	check_user(t_info *info, char *arg)
{
  t_list	*list;
  t_user	*user;

  list = info->users_list;
  if (!list)
    return (1);
  while (list)
    {
      user = list->data;
      if (user && arg && strcmp(user->name, arg) == 0)
	{
	  info->user_selected = user->name;
	  if (user->pass)
	    return (2);
	  return (1);
	}
      list = list->next;
    }
  return (0);
}

int		cmd_user(t_info *info, char *str)
{
  char		*arg;
  int		ret;
  char		buffer[256];

  if ((arg = get_cmd_arg(str)) == NULL)
    {
      send_answer(info, "Missing user name.", 501);
      return (0);
    }
  ret = check_user(info, arg);
  if (ret == 0)
    {
      info->keep_connected = 0;
      return (0);
    }
  if (ret == 1)
    {
      snprintf(buffer, 255, "User %s logged in.", arg);
      return (log_user(info, buffer, 230));
    }
  snprintf(buffer, 255, "Password required for %s.", arg);
  send_answer(info, buffer, 331);
  return (1);
}
