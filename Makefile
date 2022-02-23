# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tharland <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/06 15:13:14 by tharland          #+#    #+#              #
#    Updated: 2021/10/06 15:13:16 by tharland         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_CLIENT	=	client.c utils.c
SRCS_SERVER	=	server.c utils.c
SRCS_CLIENT_BONUS	=	client_bonus.c utils_bonus.c
SRCS_SERVER_BONUS	=	server_bonus.c utils_bonus.c
OBJS_CLIENT	=	${SRCS_CLIENT:.c=.o}
OBJS_SERVER	=	${SRCS_SERVER:.c=.o}
OBJS_CLIENT_BONUS	=	${SRCS_CLIENT_BONUS:.c=.o}
OBJS_SERVER_BONUS	=	${SRCS_SERVER_BONUS:.c=.o}
CC	=		gcc -Wall -Wextra -Werror
RM	=		rm -rf

.c.o:
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:		client server

server:	$(OBJS_SERVER) minitalk.h Makefile
			$(CC) $(OBJS_SERVER) -o server

client:	$(OBJS_CLIENT) minitalk.h Makefile
			$(CC) $(OBJS_CLIENT) -o client

bonus:		server_bonus client_bonus

server_bonus:	$(OBJS_SERVER_BONUS) minitalk_bonus.h Makefile
			$(CC) $(OBJS_SERVER_BONUS) -o server

client_bonus:	$(OBJS_CLIENT_BONUS) minitalk_bonus.h Makefile
			$(CC) $(OBJS_CLIENT_BONUS) -o client

clean:
			$(RM) $(OBJS_CLIENT) $(OBJS_SERVER) $(OBJS_CLIENT_BONUS) $(OBJS_SERVER_BONUS)

fclean:		clean
			$(RM) client server client_bonus server_bonus

re:			fclean all
.PHONY: all clean server_bonus client_bonus fclean re
