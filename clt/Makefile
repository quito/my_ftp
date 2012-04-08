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

CFLAGS	=	-Wall -Wextra -ansi -I. -ggdb -D _BSD_SOURCE -D _XOPEN_SOURCE=700

LDFLAGS	=	

SRC	=	main.c \
		init_client.c \
		init_socket.c \
		run_client.c \
		send_cmd.c \
		cut_answer.c \
		get_answer.c \
		write_secure.c \
		epur_str.c \
		cut_cmd.c \
		get_pasv.c \
		read_data.c \
		prompt.c \
		run_cmd.c \
		cmd/cmd_exit.c \
		cmd/cmd_cd.c \
		cmd/cmd_ls.c \
		cmd/cmd_put.c \
		cmd/cmd_get.c \
		cmd/cmd_pwd.c


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