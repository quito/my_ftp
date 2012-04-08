##
## Makefile for  in /home/collet_p/projet_tmp/my_ftp
## 
## Made by pierre collet
## Login   <collet_p@epitech.net>
## 
## Started on  Mon Mar 26 11:29:51 2012 pierre collet
## Last update Mon Mar 26 11:29:51 2012 pierre collet
##

NAME	=	serveur

CC	=	gcc

CFLAGS	=	-Wall -Wextra -ansi -I. -D _BSD_SOURCE -D _XOPEN_SOURCE=700 -D _GNU_SOURCE -ggdb 

LDFLAGS	=	-lcrypt

SRC	=	main.c \
		init_serv.c \
		init_socket.c \
		waiting_for_connection.c \
		list.c \
		signal_manager.c \
		client_manager.c \
		write_secure.c \
		send_answer.c \
		my_chdir.c \
		close_everything.c \
		cmd/get_cmd_arg.c \
		cmd/login.c \
		cmd/noop.c \
		cmd/user.c \
		cmd/pass.c \
		cmd/type.c \
		cmd/pwd.c \
		cmd/cwd.c \
		cmd/pasv.c \
		cmd/list.c \
		cmd/cdup.c \
		cmd/retr.c \
		cmd/mkdir.c \
		cmd/rmdir.c \
		cmd/delete.c \
		cmd/cmd_stor.c \
		cmd/quit.c

OBJ	=	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)

clean:
		rm -rf $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all

.PHONY:		all clean fclean re