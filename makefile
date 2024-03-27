# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tarekkkk <tarekkkk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/22 15:04:55 by tabadawi          #+#    #+#              #
#    Updated: 2024/03/27 21:08:16 by tarekkkk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long

CC		=	cc

CFLAGS	=	-Wall -Werror -Wextra

SRCS 	=	so_long.c \
			parsing_map.c parsing_utils.c \
			valid_path.c

OBJS	=	$(SRCS:.c=.o)

LIBFT	=	libft/libft.a

MLX		=	mlx/libmlx.a

MLXFLAG	=	-L mlx -lmlx -framework OpenGL -framework AppKit

all		:	$(NAME)

$(NAME)	:	$(OBJS) $(LIBFT) $(MLX)
	@$(CC)	$(CFLAGS) $(OBJS) $(MLXFLAG) -o $@ $(LIBFT) $(MLX)
	@ echo "SO_LONG CREATED"

$(LIBFT):
	@$(MAKE)	-C libft
	@ echo "LIBFT CREATED"

$(MLX):
	@$(MAKE)	-C mlx
	@ echo "MLX CREATED"

clean :
	@$(MAKE) -C libft clean
	@$(MAKE) -C mlx clean
	@rm -f $(OBJS)
		
fclean: clean
	@$(MAKE) -C libft fclean
	@rm -f $(NAME)

re:	fclean all
 
.PHONY: all clean fclean re