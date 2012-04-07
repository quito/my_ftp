/*
** my_chdir.c for  in /home/quito/projet_tmp/my_ftp/srv
** 
** Made by pierre collet
** Login   <collet_p@epitech.net>
** 
** Started on  Wed Apr  4 15:43:21 2012 pierre collet
** Last update Wed Apr  4 15:43:21 2012 pierre collet
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "server.h"

static char	*get_home(t_info *info)
{
  char		*home;

  if (asprintf(&home, "%s/%s/%s", info->server_path, ACCOUNT_PATH, info->user_selected) == -1)
    {
      fprintf(stderr, "Cannot rebuild user home path");
      return (NULL);
    } 
  return (home);
}

int	find_user_path(t_info *info)
{
  char	*current;
  char	*home;

  if ((current = getcwd(NULL, 255)) == NULL)
    {
      perror("getcwd");
      return (0);
    }
  strcat(current, "/");
  if (asprintf(&home, "%s/%s/%s", info->server_path, ACCOUNT_PATH, info->user_selected) == -1)
    {
      fprintf(stderr, "Cannot rebuild user home path");
      return (0);
    }
  strncpy(info->cur_path, &(current[strlen(info->server_path)
				    + strlen(ACCOUNT_PATH)
				    + strlen(info->user_selected) + 2]), 256);
  free(current);
  free(home);
  return (1);
}

static int	check_path(t_info *info)
{
  char		*current;
  char		*home;

  if ((current = getcwd(NULL, 255)) == NULL)
    {
      perror("getcwd");
      return (0);
    }
  if ((home = get_home(info)) == NULL)
    return (0);
  if (strncmp(home, current, strlen(home)) == 0)
    return (1);
  return (0);
}

static int	get_real_path(t_info *info, char *path, char **real_path)
{
  if (strlen(info->cur_path) == 0 || path[0] == '/')
    {
      if (asprintf(real_path, "%s/%s/%s/%s", info->server_path, ACCOUNT_PATH,
		   info->user_selected, path) == -1)
	{
	  fprintf(stderr, "Cannot rebuild real path\n");
	  return (0);
	}
    }
  else if (asprintf(real_path, "%s/%s/%s%s/%s", info->server_path, ACCOUNT_PATH,
		    info->user_selected, info->cur_path, path) == -1)
    {
      fprintf(stderr, "Cannot rebuild real path\n");
      return (0);
    }
  return (1);
}

int	my_chdir(char *path, t_info *info)
{
  int	ret;
  char	*real_path;

  if (get_real_path(info, path, &real_path) == 0)
    return (-1);
  ret = chdir(real_path);
  if (ret != 0)
    return (-1);
  if (!check_path(info))
    my_chdir("/", info);
  free(real_path);
  if (find_user_path(info))
    return (ret);
  return (-1);
}
