# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mjuin <mjuin@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/11 11:27:42 by mjuin             #+#    #+#              #
#    Updated: 2022/11/29 13:55:25 by mjuin            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	= clang

CFLAGS = -g -Wall -Wextra -Werror

NAME	= push_swap

LIBFT = libft/libft.a

SRC =	ft_push.c \
		ft_reverse_rotate.c \
		ft_rotate.c \
		main.c \
		ft_swap.c \
		push_swap_utils.c

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
	
