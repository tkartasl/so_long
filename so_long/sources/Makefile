# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/05 12:11:11 by tkartasl          #+#    #+#              #
#    Updated: 2024/02/05 12:31:41 by tkartasl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS = sources/so_long.c \
		sources/errors.c \
		sources/graphics.c \
		sources/graphics2.c \
		sources/map_validation.c \
		sources/map_validation2.c \
		sources/movement.c

LIBFT = libft/

LIBFT_A = libft/libft.a

MAKE = make

FLAGS = -Wall -Wextra -Werror -I includes

MLX_CC = libmlx42.a -Iinclude -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/"

CC = cc

all: ${NAME}

${NAME}: ${SRCS}
	${MAKE} all -C ${LIBFT}
	${CC} ${FLAGS} ${SRCS} ${LIBFT_A} ${MLX_CC} -o ${NAME}

clean:
	${MAKE} clean -C ${LIBFT}

fclean: clean
	rm -f ${NAME}
	${MAKE} fclean -C ${LIBFT}

re: fclean all

.PHONY: all clean fclean re