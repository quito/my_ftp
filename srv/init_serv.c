/*
** init_serv.c for  in /home/collet_p/projet_tmp/my_ftp/srv
** 
** Made by pierre collet
** Login   <collet_p@epitech.net>
** 
** Started on  Mon Mar 26 11:42:14 2012 pierre collet
** Last update Mon Mar 26 11:42:14 2012 pierre collet
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "server.h"

static int	get_opt(t_info *info, char *port)
{
  int		p;

  p = atoi(port);
  if (p > 0 && p < 0xFFFF)
    {
      info->port = p;
      return (1);
    }
  fprintf(stderr, "Error bad port try between 1 and %d\n", 0xFFFF);
  return (0);
}

static int	stock_user(t_info *info, char *line, int size, t_user *user)
{
  int		i;

  i = 0;
  if (line)
    {
      line[size - 1] = '\0';
      while (line[i] && line[i] != ':')
	i++;
      if (line[i] == ':')
	{
	  line[i] = '\0';
	  user->name = strdup(line);
	  if (strlen(&(line[i + 1])))
	    user->pass = strdup(&(line[i + 1]));
	}
      info->users_list = push_back_list(info->users_list, user);
      free(line);
    }
  return (1);
}

static int	get_users(t_info *info)
{
  FILE		*file;
  t_user	*users;
  char		*line;
  int		size;
  size_t	n;

  if ((file = fopen(USERSFILE, "r")) == NULL)
    {
      perror("fopen");
      fprintf(stderr, "Cannot open userfile\n");
      return (1);
    }
  while (!(line = NULL) && (size = getline(&line, &n, file)) > 0)
    if ((users = malloc(sizeof(*users))) == NULL ||
	stock_user(info, line, size, users) == 0)
      return (0);
  fclose(file);
  return (1);
}

static int	get_path(t_info *info)
{
  if ((info->server_path = getcwd(NULL, 256)) == NULL)
    {
      perror("getcwd");
      return (0);
    }
  return (1);
}

int	init_serv(t_info *info, char **av)
{
  if (!get_opt(info, av[1]))
    return (0);
  info->accept_connections = 1;
  info->keep_connected = 1;
  info->is_auth = 0;
  info->pid_list = NULL;
  info->users_list = NULL;
  info->is_user_selected = 0;
  info->user_selected = NULL;
  info->dtp = NULL;
  memset(info->cur_path, 0, sizeof(info->cur_path));
  if (!get_users(info) || info->users_list == NULL || !get_path(info))
    return (0);
  manage_signal(1);
  return (1);
}
