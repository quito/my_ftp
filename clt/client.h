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

# include <sys/types.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <arpa/inet.h>

typedef struct	s_info
{
  char			*serv_ip;
  int			port;
  struct sockaddr_in	sock_in;
  struct sockaddr	sockaddr;
  int			socket;
  int			keep_connected;
}			t_info;

int		init_client(t_info *info, char **av);
int		init_socket(t_info *info);
int		run_client(t_info *info);
int		get_num_answer(char *str);
char		*get_arg_answer(char *str);

#endif 
