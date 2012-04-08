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

# define IS_100(x)	(((x) >= 100 && (x) < 200) ? 1 : 0)
# define IS_200(x)	(((x) >= 200 && (x) < 300) ? 1 : 0)
# define IS_300(x)	(((x) >= 300 && (x) < 400) ? 1 : 0)
# define IS_400(x)	(((x) >= 400 && (x) < 500) ? 1 : 0)
# define IS_500(x)	(((x) >= 500 && (x) < 600) ? 1 : 0)

typedef struct	s_rep
{
  int		code;
  char		*msg;
}		t_rep;

typedef struct	s_cmd
{
  char		*cmd;
  char		*arg;
}		t_cmd;

typedef struct		s_dtp
{
  char			*ip;
  unsigned short	port;
  struct sockaddr_in	sock_in;
  struct sockaddr	sockaddr;
  int			socket;  
}			t_dtp;

typedef struct		s_info
{
  t_dtp			*dtp;
  char			*serv_ip;
  int			port;
  struct sockaddr_in	sock_in;
  struct sockaddr	sockaddr;
  int			socket;
  int			keep_connected;
}			t_info;

typedef int	(*func_cmd)(t_info *, t_cmd *);

typedef struct	s_cmd_func
{
  char		*name;
  func_cmd	func;
}		t_cmd_func;


int		init_client(t_info *info, char **av);
int		init_socket(t_info *info);
int		run_client(t_info *info);
int		get_num_answer(char *str);
int		get_answer(t_info *info, t_rep *rep);
int		write_secure(int fd, char *str, unsigned int size, t_info *info);
char		*get_arg_answer(char *str);
void		epur_str(char *str);
int		send_cmd(t_info *info, char *str, char *arg);
void		epur_str_r(char *str);
int		prompt(t_cmd *cmd);
char		*get_cmd_arg(char *str);
char		*get_cmd(char *str);
int		get_pasv(t_info *info);
int		create_dtp(t_info *info, char *ip, unsigned short port);
int		connect_dtp(t_dtp *info);
void		close_dtp(t_info *info);
int		read_data(t_info *info, int fd_in, int fd_out);
int		run_cmd(t_info *info, t_cmd *cmd);
int		cmd_exit(t_info *info, t_cmd *cmd);
int		cmd_cd(t_info *info, t_cmd *cmd);
int		cmd_get(t_info *info, t_cmd *cmd);
int		cmd_put(t_info *info, t_cmd *cmd);
int		cmd_pwd(t_info *info, t_cmd *cmd);
int		cmd_ls(t_info *info, t_cmd *cmd);
void		manage_signal();

#endif 
