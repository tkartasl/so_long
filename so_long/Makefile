# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/05 12:11:11 by tkartasl          #+#    #+#              #
#    Updated: 2024/02/08 10:13:05 by tkartasl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

NAME_BONUS = so_long_bonus

SRCS = sources/so_long.c \
		sources/errors.c \
		sources/graphics.c \
		sources/graphics2.c \
		sources/map_validation.c \
		sources/map_validation2.c \
		sources/movement.c

SRCS_BONUS = bonus_dir/so_long_bonus.c \
				bonus_dir/errors_bonus.c \
				bonus_dir/graphics_bonus.c \
				bonus_dir/graphics2_bonus.c \
				bonus_dir/map_validation_bonus.c \
				bonus_dir/map_validation2_bonus.c \
				bonus_dir/movement_bonus.c

OBJS = ${SRCS:.c=.o}

OBJS_BONUS = ${SRCS_BONUS:.c=.o}

LIBFT = libft/

MLXDIR = MLX42/build

MLX42_A = ${MLXDIR}/libmlx42.a

LIBFT_A = libft/libft.a

MAKE = make

FLAGS = -Wall -Wextra -Werror -Iincludes

MLX42_FLAGS = -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/"

CC = cc ${FLAGS}

CC_BONUS = cc -Wall -Wextra -Werror

all: ${NAME}

mlx42lib: ${MLX42_A} 

${MLX42_A}: ${MLXDIR}
	${MAKE} -C ${MLXDIR} -j4

${MLXDIR}:
	cmake MLX42 -B MLX42/build

%.o: %.c
	${CC} -o $@ -c $<

${NAME}: ${OBJS} ${LIBFT_A} ${MLX42_A}
	${CC} ${OBJS} ${LIBFT_A} ${MLX42_A} ${MLX42_FLAGS} -o ${NAME}

${LIBFT_A}:
	${MAKE} -C ${LIBFT}

bonus: ${NAME_BONUS}

${NAME_BONUS}: ${OBJS_BONUS} ${LIBFT_A} ${MLX42_A}
	${CC_BONUS} ${OBJS_BONUS} ${LIBFT_A} ${MLX42_A} ${MLX42_FLAGS} -o ${NAME_BONUS}

clean:
	${MAKE} clean -C ${LIBFT}
	rm -rf ${OBJS}
	rm -rf ${MLXDIR}
	rm -rf ${OBJS_BONUS}
	
fclean: clean
	rm -f ${NAME}
	rm -rf ${NAME_BONUS}
	${MAKE} fclean -C ${LIBFT}

re: fclean all

.PHONY: re, fclean, clean, all, mlx42lib bonus