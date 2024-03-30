# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/22 15:04:55 by tabadawi          #+#    #+#              #
#    Updated: 2024/03/30 14:08:04 by tabadawi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

define SONIC


                           -+#%%%%%-              
                     -*%%%%%%%%%%*                
                 :+%%%%%%%%%%%%%=                 
               +%%%%%%%%%%%%%%%=                  
             #%%%%%%%%%%%%%%%%#*%%%%%%+-          
           +%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%=      
          #%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%#:   
        :%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%#  
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%###=
       +%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%+-       
      -%%%%%%%%%%%+   -#%%%%%%%%%%%%%%+           
+#%%%%%%%%%%%%%%%.      %%%%%%%%%%%%%%+           
 %%%%%%%%%%%%%%%*  =    :%%%%%%%%%%%%%%%%.        
  =%%%%%%%%%%%%%*  =%%.  %%%%%%%%%%%%%%%%%+       
    =%%%%%%%%%%%*   =%%:+%%%%%%%%%%%%%%%%%%#      
     .#%-=%%%%%%*     -%%%%%%%%%%%%%%%%%%%%%#     
       .#= #%%%%:   .#%%%%%%########%%%%%%%%%=    
          =--###%%%%%%%%%%+            :+#%%%%    
           :+%%%%%%%%%%=                   .+%=   
           %%+                                    


endef
export SONIC

BLUE	=	$'\x1b[34m

NAME	=	so_long

CC		=	cc

CFLAGS	=	-Wall -Werror -Wextra

SRCS 	=	so_long.c \
			parsing_map.c parsing_utils.c valid_path.c \
			rendering.c game.c game_ending.c 

OBJS	=	$(SRCS:.c=.o)

LIBFT	=	libft/libft.a

PRINTF	=	ft_printf/libftprintf.a	

MLX		=	mlx/libmlx.a

MLXFLAG	=	-L mlx -lmlx -framework OpenGL -framework AppKit

all		:	$(NAME)

$(NAME)	:	$(OBJS) $(LIBFT) $(MLX) $(PRINTF)
	@$(CC)	$(CFLAGS) $(OBJS) $(MLXFLAG) -o $@ $(LIBFT) $(MLX) $(PRINTF)
	@ echo "${BLUE}$$SONIC"

$(LIBFT):
	@$(MAKE)	-C libft

$(PRINTF):
	@$(MAKE)	-C ft_printf

$(MLX):
	@$(MAKE)	-C mlx

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