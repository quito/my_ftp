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

CFLAGS	=	-Wall -Wextra -ansi -I. -D _BSD_SOURCE -D _XOPEN_SOURCE=700  -ggdb 

LDFLAGS	=	-lcrypt

SRC	=	main.c \
		init_serv.c \
		init_socket.c \
		waiting_for_connection.c \
		list.c \
		signal_manager.c \
		client_manager.c \
		ls_dir.c \
		write_secure.c \
		send_answer.c \
		cmd/get_cmd_arg.c \
		cmd/noop.c \
		cmd/user.c

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