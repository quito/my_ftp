/*
** ls_dir.c for  in /home/quito/projet_tmp/my_ftp/srv
** 
** Made by pierre collet
** Login   <collet_p@epitech.net>
** 
** Started on  Tue Apr  3 09:40:54 2012 pierre collet
** Last update Tue Apr  3 09:40:54 2012 pierre collet
*/

#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include "server.h"


int		ls_dir(t_info *info)
{
  DIR		*dir;
  struct dirent	*file;

  (void)info;
  dir = opendir(".");
  if (dir == NULL)
    {
      perror("opendir");
      return (0);
    }
  while ((file = readdir(dir)) != NULL)
    {
      
    }
  if (closedir(dir) == -1)
    {
      perror("closedir");
      return (0);
    }
  return (1);
}
