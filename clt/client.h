/*
** client.h for  in /home/collet_p/projet_tmp/my_ftp/clt
** 
** Made by pierre collet
** Login   <collet_p@epitech.net>
** 
** Started on  Mon Mar 26 11:40:20 2012 pierre collet
** Last update Mon Mar 26 11:40:20 2012 pierre collet
*/

#ifndef CLIENT_H_
# define CLIENT_H_

typedef struct	s_info
{
  char		*serv_ip;
  int		port;
}		t_info;

int		init_client(t_info *info, char **av);

#endif 
