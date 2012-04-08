/*
** retr.c for  in /home/quito/projet_tmp/my_ftp/srv
** 
** Made by pierre collet
** Login   <collet_p@epitech.net>
** 
** Started on  Sat Apr  7 02:22:10 2012 pierre collet
** Last update Sat Apr  7 02:22:10 2012 pierre collet
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include "server.h"

static int	open_file(t_info *info, char *arg, int *size)
{
  int		fd;
  char		buffer[512];
  struct stat	buf;

  snprintf(buffer, sizeof(buffer), "%s/%s/%s%s/%s",
	   info->server_path, ACCOUNT_PATH,
	   info->user_selected, info->cur_path, arg);
  printf("%s\n", buffer);
  if (stat(buffer, &buf) == -1)
    {
      send_answer(info, "No such file or directory", 550);
      return (0);
    }
  if ((fd = open(buffer, O_RDONLY)) == -1)
    {
      send_answer(info, "No such file or directory", 550);
      return (-1);
    }
  *size = buf.st_size;
  return (fd);
}

static int	build_buffer(t_info *info, char *buffer, char *arg, int size)
{
  if (info->data_type == TYPE_I)
    {
      snprintf(buffer, 512, "Opening BINARY mode data"
	       " connection for %s (%d bytes)", arg, size);
      return (1);
    }
  else if (info->data_type == TYPE_A)
    {
      snprintf(buffer, 512, "Opening ASCII mode data"
	       " connection for %s (%d bytes)", arg, size);
      return (1);
    }
  else
    return (0);
}

int		accept_pasv_connection(t_info *info)
{
  unsigned int	size;

  size = sizeof(info->dtp->sin_client);
  if ((info->dtp->c_sock = accept(info->dtp->socket,
				  (struct sockaddr *)(&(info->dtp->sin_client)),
				  &size)) == -1)
    {
      perror("accept");
      send_answer(info, "Cannot accept connection", 425);
      return (0);
    }
  return (1);
}

static int	send_file(t_info *info, int fd)
{
  char		buffer[512];
  int		ret;
  unsigned int	i;

  if (!(info->dtp))
    {
      send_answer(info, "DTP not opened", 550);
      return (0);
    }
  if (!accept_pasv_connection(info))
    return (0);
  while ((ret = read(fd, buffer, sizeof(buffer))) > 0)
    {
      i = 0;
      while (i < (unsigned int)ret)
	{
	  if (info->data_type == TYPE_A && buffer[i] == '\n' &&
	      (i == 0  || buffer[i - 1] != '\r'))
	    write_secure(info->dtp->c_sock, "\r\n", 2, info);
	  else
	    write_secure(info->dtp->c_sock, &(buffer[i]), 1, info);
	  i++;
	}
    }
  return (1);
}

int		cmd_retr(t_info *info, char *str)
{
  char		*arg;
  int		fd;
  int		size;
  char		buffer[512];

  if ((arg = get_cmd_arg(str)) == NULL || (!arg) || strlen(arg) <= 0)
    {
      send_answer(info, "Missing argument", 501);
      return (0);
    }
  if ((fd = open_file(info, arg, &size)) == -1)
      return (0);
  if (!build_buffer(info, buffer, arg, size))
    {
      send_answer(info, "Bad Type chose A or I", 500);
      return (0);
    }
  send_answer(info, buffer, 150);
  send_file(info, fd);
  close(fd);
  send_answer(info, "Transfer complete.", 226);
  close_dtp(info);
  return (1);
}
