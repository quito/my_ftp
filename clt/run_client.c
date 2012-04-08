/*
** run_client.c for  in /home/quito/projet_tmp/my_ftp/clt
** 
** Made by pierre collet
** Login   <collet_p@epitech.net>
** 
** Started on  Mon Apr  2 20:28:16 2012 pierre collet
** Last update Mon Apr  2 20:28:16 2012 pierre collet
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "client.h"

static int	login_pass(t_info *info)
{
  char		buffer[512];
  t_rep		rep;

  memset(buffer, 0, sizeof(buffer));
  if (write(1, "Pass: ", 6) == -1)
    return (0);
  if (read(0, buffer, sizeof(buffer) - 1) > 0)
    {
      epur_str(buffer);
      if (!send_cmd(info, "PASS", buffer))
	return (0);
      if (!get_answer(info, &rep))
	return (0);
      if (!(IS_200(rep.code)))
	return (0);
      return (1);
    }
  else
    return (0);
  return (1);
}

static int	login_user(t_info *info, t_rep *rep)
{
  char		buffer[512];
  t_rep		rep_login;

  if (!(IS_200(rep->code)) || write(1, "User: ", 6) == -1)
    return (0);
  memset(buffer, 0, sizeof(buffer));
  if (read(0, buffer, sizeof(buffer) - 1) > 0)
    {
      epur_str(buffer);
      if (!send_cmd(info, "USER", buffer))
	return (0);
      if (!get_answer(info, &rep_login))
	return (0);
      if (IS_200(rep_login.code))
	return (1);
      if (IS_300(rep_login.code))
	return (login_pass(info));
      return (0);
    }
  else
    return (0);
  return (1);
}

static int	open_session(t_info *info)
{
  t_rep		rep;

  if (!get_answer(info, &rep))
    {
      info->keep_connected = 0;
      return (0);
    }
  return (login_user(info, &rep));
}

int		run_client(t_info *info)
{
  t_cmd		cmd;

  printf("[*] Waiting for Welcome message\n");
  if (!open_session(info))
    info->keep_connected = 0;
  while (info->keep_connected)
    {
      memset(&cmd, 0, sizeof(cmd));
      if (!prompt(&cmd))
	info->keep_connected = 0;
      else
	{
	  run_cmd(info, &cmd);
	  free(cmd.cmd);
	  free(cmd.arg);
	}
    }
  printf("[*] Disconnected from server\n");
  return (1);
}
