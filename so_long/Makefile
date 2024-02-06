# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/05 12:11:11 by tkartasl          #+#    #+#              #
#    Updated: 2024/02/06 14:55:59 by tkartasl         ###   ########.fr        #
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

OBJS = ${SRCS:.c=.o}

LIBFT = libft/

MLXDIR = MLX42

HEADERS = -I ${MLXDIR}/include

MLX42_A = MLX42/build/libmlx42.a -Iinclude -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/"

LIBFT_A = libft/libft.a

MAKE = make

FLAGS = -Wall -Wextra -Werror -Iincludes

CC = cc ${FLAGS}

all: mlx42lib ${NAME}

mlx42lib:
	cmake ${MLXDIR} -B ${MLXDIR}/build && ${MAKE} -C ${MLXDIR}/build -j4

%.o: %.c
	${CC} -o $@ -c $< ${HEADERS}

${NAME}: ${OBJS} ${LIBFT_A}
	${CC} ${OBJS} ${MLX42_A} ${LIBFT_A} -o ${NAME}

${LIBFT_A}:
	${MAKE} -C ${LIBFT}

clean:
	${MAKE} clean -C ${LIBFT}
	rm -rf ${OBJS}
	rm -rf ${MLXDIR}/build

fclean: clean
	rm -f ${NAME}
	${MAKE} fclean -C ${LIBFT}

re: fclean all

.PHONY: re, fclean, clean, all, mlx42lib 