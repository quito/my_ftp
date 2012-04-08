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
# define ACCOUNT_PATH	"account"
# define WELCOME_MSG	"Welcome on my server"
# define BUFF_SIZE	256
# define TYPE_A		1
# define TYPE_I		2

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

typedef struct		s_pasv_dtp
{
  int			port;
  int			socket;
  struct sockaddr_in	sin;
  struct sockaddr_in	sin_client;
  int			accept_connections;
  int			c_sock;
}			t_pasv_dtp;

typedef struct		s_info
{
  t_pasv_dtp		*dtp;
  t_list		*pid_list;
  t_list		*users_list;
  int			is_auth;
  int			is_user_selected;
  char			*user_selected;
  int			data_type;

  char			cur_path[256];
  char			*server_path;

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
int		my_chdir(char *path, t_info *info);
char		*get_cmd_arg(char *str);
void		delete_endline(char *str);
int		log_user(t_info *info, char *buffer, int nb);
int		cmd_noop(t_info *info, char *str);
int		cmd_user(t_info *info, char *str);
int		cmd_pass(t_info *info, char *str);
int		cmd_pwd(t_info *info, char *str);
int		cmd_type(t_info *info, char *str);
int		cmd_pasv(t_info *info, char *str);
int		cmd_list(t_info *info, char *str);
int		cmd_cdup(t_info *info, char *str);
int		cmd_cwd(t_info *info, char *str);
int		cmd_retr(t_info *info, char *str);
int		close_dtp(t_info *info);
int		cmd_mkdir(t_info *info, char *str);
int		cmd_rmdir(t_info *info, char *str);
int		cmd_stor(t_info *info, char *str);
int		cmd_delete(t_info *info, char *str);
int		cmd_quit(t_info *info, char *str);
int		accept_pasv_connection(t_info *info);
void		close_everything(t_info *info);

#endif
