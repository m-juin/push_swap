# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mjuin <mjuin@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/11 11:27:42 by mjuin             #+#    #+#              #
#    Updated: 2022/12/09 10:44:54 by mjuin            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	= clang

CFLAGS = -g -Wall -Wextra -Werror

NAME	= push_swap

LIBFT = libft/libft.a

SRC =	srcs/ft_push.c \
		srcs/ft_reverse_rotate.c \
		srcs/ft_rotate.c \
		srcs/main.c \
		srcs/ft_swap.c \
		srcs/push_swap_utils.c \
		srcs/algo.c \
		srcs/algo_utils.c \
		srcs/algo_radix.c \
		srcs/lst_utils.c \
		srcs/movement_utils.c \
		srcs/free.c

OBJS =	${SRC:.c=.o}

RM	=	rm -f

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all:	${NAME}

$(LIBFT):
	make -C libft

$(NAME):	$(LIBFT) ${OBJS} 
	${CC} ${CFLAGS} ${OBJS} ${LIBFT} -o ${NAME}


clean:
	${RM} ${OBJS}
	make fclean -C libft

fclean:	clean
	${RM} ${NAME}

re: fclean all

.PHONY:
	all clean fclean re
	
