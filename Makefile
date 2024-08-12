# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alkaram <alkaram@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/05 22:12:49 by alkaram           #+#    #+#              #
#    Updated: 2024/05/06 15:58:07 by alkaram          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fdf
LIBFT		=	libft/
MLX			=	minilibx-linux/
LIBFT_A		=	$(addprefix $(LIBFT), libft.a)
MLX_A		=	$(addprefix $(MLX), libmlx.a)

CC			=	gcc
INCLUDE 	=	includes
CFLAGS		=	-Wall -Wextra -Werror -I$(INCLUDE) -g
RM			=	rm -f
SRCS		=	fildefer.c \
                algorithms.c \
                draw_projection.c \
                keyboard.c \
                line_algorithm.c \
                project.c \
                parse_maps.c \
                utils.c \
                main.c \
                rotate.c \
                get_next_line/get_next_line.c \
                get_next_line/get_next_line_utils.c 

OBJS		=	$(SRCS:%.c=%.o)

all:			$(NAME)

$(NAME):		$(OBJS) $(LIBFT_A) $(MLX_A)
	@$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT) -lft -L$(MLX) -lmlx -lm -o $(NAME) -lXext -lX11
	@echo "Linked into executable \033[0;32mfdf\033[0m."

$(LIBFT_A):
	@$(MAKE) -s -C $(LIBFT)
	@echo "Compiled $(LIBFT_A)."

$(MLX_A):
	@$(MAKE) -s -C $(MLX)
	@echo "Compiled $(MLX_A)."

bonus:			all

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiling $<."

localclean:
	@$(RM) $(OBJS)
	@echo "Removed object files."

clean:			localclean
	@$(MAKE) clean -s -C $(LIBFT)
	@echo "Clean libft."
	@$(MAKE) clean -s -C $(MLX)
	@echo "Clean mlx."

fclean:			localclean
	@$(MAKE) fclean -s -C $(LIBFT)
	@echo "Full clean libft."
	@if $(MAKE) fclean -s -C $(MLX); then \
        echo "Clean mlx."; \
    else \
        $(RM) $(MLX_A); \
        echo "Removed $(MLX_A)."; \
    fi
	@$(RM) $(NAME)
	@echo "Removed executable."

re:				fclean all

.PHONY:			all clean fclean re localclean bonus