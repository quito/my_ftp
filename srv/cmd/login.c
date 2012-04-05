/*
** login.c for  in /home/quito/projet_tmp/my_ftp/srv
** 
** Made by pierre collet
** Login   <collet_p@epitech.net>
** 
** Started on  Wed Apr  4 14:29:13 2012 pierre collet
** Last update Wed Apr  4 14:29:13 2012 pierre collet
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "server.h"

static int	move_to_home(t_info *info)
{
  char		buffer[256];

  snprintf(buffer, 255, "%s/%s", ACCOUNT_PATH, info->user_selected);
  if (my_chdir("/", info) == -1)
    {
      if (errno == ENOENT)
	{
	  if (mkdir(buffer, 0755) == -1 && errno != EEXIST)
	    {
	      perror("mkdir");
	      info->is_auth = 0;
	      info->keep_connected = 0;
	      return (0);
	    }
	  else if (my_chdir("/", info) != -1)
	    return (1);
	}
      return (0);
    }
  return (1);
}

int		log_user(t_info *info, char *buffer, int nb)
{
  info->is_auth = 1;
  send_answer(info, buffer, nb);
  if (move_to_home(info) == 0)
    {
      info->keep_connected = 0;
      printf("%s\n", info->cur_path);
      return (0);
    }
  return (1);
}
