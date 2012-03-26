/*
** server.h for  in /home/collet_p/projet_tmp/my_ftp/srv
** 
** Made by pierre collet
** Login   <collet_p@epitech.net>
** 
** Started on  Mon Mar 26 11:38:50 2012 pierre collet
** Last update Mon Mar 26 11:38:50 2012 pierre collet
*/

#ifndef SERVER_H_
# define SERVER_H_

typedef struct	s_info
{
  int		port;
}		t_info;

int		init_serv(t_info *info, char **av);

#endif
