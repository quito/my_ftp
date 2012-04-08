/*
** cmd_ls.c for  in /home/quito/projet_tmp/my_ftp/clt
** 
** Made by pierre collet
** Login   <collet_p@epitech.net>
** 
** Started on  Sat Apr  7 22:32:37 2012 pierre collet
** Last update Sat Apr  7 22:32:37 2012 pierre collet
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "client.h"

int		cmd_ls(t_info *info, t_cmd *cmd)
{
  t_rep		rep;

  (void)cmd;
  if (!get_pasv(info))
    return (0);
  send_cmd(info, "LIST", cmd->arg);
  if (get_answer(info, &rep) && rep.code == 150 &&
      connect_dtp(info->dtp) && read_data(info, info->dtp->socket, 1))
    {
      if (get_answer(info, &rep) && IS_200(rep.code))
	{
	  close_dtp(info);
	  return (1);
	}
      close_dtp(info);
      return (0);
    }
  close_dtp(info);
  return (1);
}
