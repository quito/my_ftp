/*
** delete.c for  in /home/quito/projet_tmp/my_ftp/srv
** 
** Made by pierre collet
** Login   <collet_p@epitech.net>
** 
** Started on  Sat Apr  7 13:51:11 2012 pierre collet
** Last update Sat Apr  7 13:51:11 2012 pierre collet
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "server.h"

int		cmd_delete(t_info *info, char *str)
{
  char		*arg;
  char		buffer[512];
  char		buf[256];

  if ((arg = get_cmd_arg(str)) == NULL)
    {
      send_answer(info, "Missing Argument.", 501);
      return (0);
    }
  snprintf(buffer, sizeof(buffer), "%s/%s/%s%s",
	   info->server_path, ACCOUNT_PATH,
  	   info->user_selected, arg);
  if (remove(arg) == -1)
    {
      send_answer(info, "Cannot delete file", 550);
      return (0);
    }
  snprintf(buf, sizeof(buf), "\"/%s\" - File successfully deleted", arg);
  send_answer(info, buf, 257);
  return (1);
}
