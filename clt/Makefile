##
## Makefile for  in /home/collet_p/projet_tmp/my_ftp
## 
## Made by pierre collet
## Login   <collet_p@epitech.net>
## 
## Started on  Mon Mar 26 11:29:51 2012 pierre collet
## Last update Mon Mar 26 11:29:51 2012 pierre collet
##

NAME	=	client

CC	=	gcc

CFLAGS	=	-Wall -Wextra -ansi -ggdb -D _BSD_SOURCE

LDFLAGS	=	

SRC	=	main.c \
		init_client.c \
		init_socket.c \
		run_client.c \
		send_cmd.c \
		cut_answer.c \
		get_answer.c

OBJ	=	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) $(OBJ) -o $(NAME)

clean:
		rm -rf $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all

.PHONY:		all clean fclean re