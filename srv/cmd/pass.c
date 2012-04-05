/*
** pass.c for  in /home/quito/projet_tmp/my_ftp/srv
** 
** Made by pierre collet
** Login   <collet_p@epitech.net>
** 
** Started on  Wed Apr  4 12:02:25 2012 pierre collet
** Last update Wed Apr  4 12:02:25 2012 pierre collet
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "server.h"

static int	check_pass(t_info *info, char *arg)
{
  t_list	*list;
  t_user	*user;
  char		*pass;

  list = info->users_list;
  if (!arg && strlen(arg) <= 0)
    return (0);
  if ((pass = crypt(arg, "$6$ft")) != NULL)
    {
      while (list)
	{
	  user = list->data;
	  if (user && arg && strcmp(user->pass, pass) == 0 &&
	      strcmp(user->name, info->user_selected) == 0)
	    return (1);
	  list = list->next;
	}
    }
  else
    fprintf(stderr, "Cannot perform a crypt\n");
  return (0);
}

int		cmd_pass(t_info *info, char *str)
{
  char		*arg;
  int		ret;
  char		buffer[256];

  if ((arg = get_cmd_arg(str)) == NULL)
    {
      send_answer(info, "Missing password.", 501);
      return (0);
    }
  ret = check_pass(info, arg);
  if (ret == 0)
    {
      snprintf(buffer, 255, "Bad password.");
      send_answer(info, buffer, 530);
      info->keep_connected = 0;
      return (0);
    }
  if (ret == 1)
    {
      snprintf(buffer, 255, "User %s logged in.", info->user_selected);
      return (log_user(info, buffer, 230));
    }
  return (1);
}
