/*
** cwd.c for  in /home/quito/projet_tmp/my_ftp/srv/cmd
** 
** Made by pierre collet
** Login   <collet_p@epitech.net>
** 
** Started on  Fri Apr  6 02:17:33 2012 pierre collet
** Last update Fri Apr  6 02:17:33 2012 pierre collet
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdlib.h>
#include "server.h"

int		cmd_cwd(t_info *info, char *str)
{
  char		*arg;

  if ((arg = get_cmd_arg(str)) == NULL)
    {
      send_answer(info, "Invalid number of arguments.", 501);
      return (0);
    }
  if (my_chdir(arg, info) == -1)
    {
      send_answer(info, "No such file or directory.", 500);
      return (0);
    }
  send_answer(info, "CWD command successful.", 250);
  return (1);
}
