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

int	my_chdir(char *path, t_info *info)
{
  int	ret;
  char	*real_path;

  /* if (asprintf(&real_path, "%s/%s/%s/%s", info->server_path, ACCOUNT_PATH, info->user_selected, path) == -1) */
  if (asprintf(&real_path, "%s/%s/%s/%s", info->server_path, ACCOUNT_PATH, info->user_selected, path) == -1)
    {
      fprintf(stderr, "Cannot rebuild real path\n");
      return (-1);
    }
  
  ret = chdir(real_path);
  if (ret != 0)
    {
      /* perror("chdir"); */
      return (-1);
    }
  free(real_path);
  if (find_user_path(info))
    return (ret);
  return (-1);
}
