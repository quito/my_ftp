/*
** cmd_cd.c for  in /home/collet_p/projet_tmp/my_ftp
** 
** Made by pierre collet
** Login   <collet_p@epitech.net>
** 
** Started on  Sun Apr  8 19:35:55 2012 pierre collet
** Last update Sun Apr  8 19:35:55 2012 pierre collet
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "client.h"

int		cmd_cd(t_info *info, t_cmd *cmd)
{
  t_rep		rep;

  if (!send_cmd(info, "CWD", cmd->arg) || !get_answer(info, &rep))
    return (0);
  if (IS_200(rep.code))
    return (1);
  return (0);
}
