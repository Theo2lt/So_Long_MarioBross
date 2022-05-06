# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user <user@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/04 21:22:24 by tliot             #+#    #+#              #
#    Updated: 2022/05/03 12:17:32 by user             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR =       .


SRCS	        =   ft_parsing.c \
					ft_verif_map.c \
					ft_free_tab.c \
					ft_strchr.c \
					ft_verif_name_map.c \
					ft_get_next_line.c \
					ft_verif_arg.c \
					main.c \
					ft_lst.c \
					ft_verif_item.c \




OBJS			=	$(addprefix $(SRC_DIR)/, $(SRCS:%.c=%.o))

NAME			=	so_long

CC				=	gcc

CFLAGS			=	-Wall -Wextra -Werror -Imlx -Imlx_linux -lXext -lX11 -lm -lz

RM				=	rm -f

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz minilibx-linux/libmlx.a -o $(NAME) $(OBJS) 

bonus:	$(OBJS2)
		$(CC) $(CFLAGS) -o $(NAME2) $(OBJS2)


all:		${NAME}

clean:
	${RM} ${OBJS} ${OBJS2}

fclean:		clean
		${RM} ${NAME} ${NAME2}

re:			fclean all

.PHONY: 	all clean fclean re
