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

CFLAGS	=	-Wall -Wextra -ansi -ggdb -D _BSD_SOURCE

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
		send_fail.c \
		send_error.c

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