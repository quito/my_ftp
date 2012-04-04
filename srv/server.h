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

# include <arpa/inet.h>

# define USERSFILE	"users.ftp"
# define WELCOME_MSG	"Welcome on my server"
# define BUFF_SIZE	256

typedef struct		s_list
{
  void			*data;
  struct s_list		*next;
}			t_list;

typedef struct		s_user
{
  char			*name;
  char			*pass;
}			t_user;

typedef struct		s_info
{
  t_list		*pid_list;
  t_list		*users_list;
  int			port;
  int			socket;
  struct sockaddr_in	sin;
  struct sockaddr_in	sin_client;
  int			accept_connections;
  int			keep_connected;
  int			csock;
}			t_info;

typedef int		(*cmd_ptr)(t_info *, char *);

typedef struct		s_cmd
{
  char			*name;
  cmd_ptr		ptr;
  int			category;
}			t_cmd;

int		init_serv(t_info *info, char **av);
int		init_socket(t_info *info);
int		waiting_for_connection(t_info *info);
void		freelist(t_list *list);
t_list		*push_back_list(t_list *list, void *data);
void		waiting_for_pid(t_list *list);
int		client_manager(t_info *info);
void		manage_signal(void);
int		write_secure(int fd, char *str, unsigned int size, t_info *info);
int		send_answer(t_info *info, char *str, int num);
char		*get_cmd_arg(char *str);
int		cmd_noop(t_info *info, char *str);
int		cmd_user(t_info *info, char *str);

#endif
