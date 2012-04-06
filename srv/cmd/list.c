/*
** list.c for  in /home/quito/projet_tmp/my_ftp/srv/cmd
** 
** Made by pierre collet
** Login   <collet_p@epitech.net>
** 
** Started on  Fri Apr  6 02:27:40 2012 pierre collet
** Last update Fri Apr  6 02:27:40 2012 pierre collet
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "server.h"

static int	close_dtp(t_info *info)
{
  close(info->dtp->socket);
  close(info->dtp->c_sock);
  free(info->dtp);
  info->dtp = NULL;
  return (0);
}

static int	send_file(t_info *info, FILE *file)
{
  char		buffer[512];
  int		ret;
  unsigned int	size;

  size = sizeof(info->dtp->sin_client);
  if ((info->dtp->c_sock = accept(info->dtp->socket,
				  (struct sockaddr *)(&(info->dtp->sin_client)),
				  &size)) == -1)
    {
      perror("accept");
      close_dtp(info);
    }
  memset(buffer, 0, 512);
  while ((ret = fread(buffer, 512, 1, file)) > 0)
    {
      write_secure(info->dtp->c_sock, buffer, ret, info);
      printf("%s", buffer);
      memset(buffer, 0, 512);
    }
  return (1);
}

int		cmd_list(t_info *info, char *str)
{
  FILE		*file;

 (void)str;
  if (info->dtp == NULL)
    {
      send_answer(info, "Data canal is not open", 425);
      return (close_dtp(info));
    }
  if ((file = popen("ls -l", "r")) == NULL)
    {
      send_answer(info, "Cannot list directory", 500);
      return (close_dtp(info));
    }
  send_answer(info, "Opening ASCII mode data connection for file list", 150);
  send_file(info, file);
  pclose(file);
  return (1);
}
