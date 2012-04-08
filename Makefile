##
## Makefile for  in /home/collet_p/projet_tmp/my_ftp
## 
## Made by pierre collet
## Login   <collet_p@epitech.net>
## 
## Started on  Mon Mar 26 11:33:46 2012 pierre collet
## Last update Mon Mar 26 11:33:46 2012 pierre collet
##

CLIENT_PATH	=	clt/

SRV_PATH	=	srv/

all:
		$(MAKE) -C $(CLIENT_PATH)
		$(MAKE) -C $(SRV_PATH)
		cp -f $(CLIENT_PATH)/client .
		cp -f $(SRV_PATH)/serveur .
		cp -f $(SRV_PATH)/users.ftp .

clean:
		$(MAKE) clean -C $(CLIENT_PATH)
		$(MAKE) clean -C $(SRV_PATH)

fclean:
		$(MAKE) fclean -C $(CLIENT_PATH)
		$(MAKE) fclean -C $(SRV_PATH)
		rm -f ./client
		rm -f ./serveur

re:		fclean all