# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tarekkkk <tarekkkk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/22 15:04:55 by tabadawi          #+#    #+#              #
#    Updated: 2024/03/29 21:35:29 by tarekkkk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long

CC		=	cc

CFLAGS	=	-Wall -Werror -Wextra -fsanitize=address -g3

SRCS 	=	so_long.c \
			parsing_map.c parsing_utils.c valid_path.c \
			rendering.c game.c game_utils.c game_ending.c 

OBJS	=	$(SRCS:.c=.o)

LIBFT	=	libft/libft.a

PRINTF	=	ft_printf/libftprintf.a	

MLX		=	mlx/libmlx.a

MLXFLAG	=	-L mlx -lmlx -framework OpenGL -framework AppKit

all		:	$(NAME)

$(NAME)	:	$(OBJS) $(LIBFT) $(MLX) $(PRINTF)
	@$(CC)	$(CFLAGS) $(OBJS) $(MLXFLAG) -o $@ $(LIBFT) $(MLX) $(PRINTF)
	@ echo "SO_LONG CREATED"

$(LIBFT):
	@$(MAKE)	-C libft
	@ echo "LIBFT CREATED"

$(PRINTF):
	@$(MAKE)	-C ft_printf
	@ echo "PRINTF CREATED"

$(MLX):
	@$(MAKE)	-C mlx
	@ echo "MLX CREATED"

clean :
	@$(MAKE) -C libft clean
	@$(MAKE) -C ft_printf clean
	@rm -f $(OBJS)
		
fclean: clean
	@$(MAKE) -C libft fclean
	@$(MAKE) -C ft_printf fclean
	@$(MAKE) -C mlx clean
	@rm -f $(NAME)

re:	fclean all
 
.PHONY: all clean fclean re