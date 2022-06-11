# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tliot <tliot@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/04 21:22:24 by tliot             #+#    #+#              #
#    Updated: 2022/06/11 16:20:46 by tliot            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR =       mendatory
SRC_DIRBONUS =       bonus

SRCS	=	mendatory/ft_affichage2.c          \
			mendatory/ft_affichage3.c          \
			mendatory/ft_affichage4.c          \
			mendatory/ft_affichage.c           \
			mendatory/ft_change_block.c        \
			mendatory/ft_exit.c                \
			mendatory/ft_free.c                \
			mendatory/ft_get_next_line.c       \
			mendatory/ft_init_t_data2.c        \
			mendatory/ft_init_t_data3.c        \
			mendatory/ft_init_t_data4.c        \
			mendatory/ft_init_t_data.c         \
			mendatory/ft_itoa.c                \
			mendatory/ft_lst.c                 \
			mendatory/ft_mouve_perso.c         \
			mendatory/ft_my_mxl_img_put.c      \
			mendatory/ft_my_string_put.c       \
			mendatory/ft_parsing.c             \
			mendatory/ft_strchr.c              \
			mendatory/ft_verif_arg.c           \
			mendatory/ft_verif_item.c          \
			mendatory/ft_verif_map.c           \
			mendatory/ft_verif_name_map.c      \
			mendatory/main.c                   

SRCSBONUS = bonus/ft_affichage2_bonus.c          \
			bonus/ft_affichage3_bonus.c          \
			bonus/ft_affichage4_bonus.c          \
			bonus/ft_affichage_bonus.c           \
			bonus/ft_change_block_bonus.c        \
			bonus/ft_exit_bonus.c                \
			bonus/ft_free_bonus.c                \
			bonus/ft_get_next_line_bonus.c       \
			bonus/ft_init_t_data2_bonus.c        \
			bonus/ft_init_t_data3_bonus.c        \
			bonus/ft_init_t_data4_bonus.c        \
			bonus/ft_init_t_data_bonus.c         \
			bonus/ft_itoa_bonus.c                \
			bonus/ft_lst_bonus.c                 \
			bonus/ft_mouve_perso_bonus.c         \
			bonus/ft_my_mxl_img_put_bonus.c      \
			bonus/ft_my_string_put_bonus.c       \
			bonus/ft_parsing_bonus.c             \
			bonus/ft_strchr_bonus.c              \
			bonus/ft_verif_arg_bonus.c           \
			bonus/ft_verif_item_bonus.c          \
			bonus/ft_verif_map_bonus.c           \
			bonus/ft_verif_name_map_bonus.c      \
			bonus/main_bonus.c                   


OBJS			=	$(SRCS:%.c=%.o)
OBJSBONUS		=	$(SRCSBONUS:%.c=%.o)
NAME			=	so_long
CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror -g3
#-Imlx -Imlx_linux -lXext -lX11 -lm -lz

RM				=	rm -f

all:		${NAME}

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
		
$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS)  minilibx-linux/libmlx_Linux.a -lXext -lX11 -I minilibx-linux/include/  -o $(NAME) 

bonus: $(NAME)_bonus 

$(NAME)_bonus:	$(OBJSBONUS)
		$(CC) $(CFLAGS) $(OBJSBONUS)  minilibx-linux/libmlx_Linux.a -lXext -lX11 -I minilibx-linux/include/  -o $(NAME)_bonus

clean:
	${RM} ${OBJS} ${OBJSBONUS}

fclean:		clean
		${RM} ${NAME} ${NAME}_bonus

re:			fclean all

.PHONY: 	all clean fclean re
