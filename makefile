# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/22 15:04:55 by tabadawi          #+#    #+#              #
#    Updated: 2024/04/05 13:13:58 by tabadawi         ###   ########.fr        #
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

define SUPERSONIC

              %%#                       
              %%%%#        ##           
             #%%%%%%       %%%          
             %%%%%%%%     #%%%%%        
             %%%%%%%%#    %%%%%%        
            %%%%%%%%%%   %%%%%%%%       
           #%%%%%%%%%%% %%%%%%%%%       
           %%%%%%%%%%%%%%%%%%%%%%     %#
          %%%%%%%%%%%%%%%%%%%%%%%#  #%%%
         %%%%%%%%%%%%%%%%%%%%%%%%#%%%%%%
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%#
  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% 
   #%%%%%%%%%%%%%%%%##%%%%%%%%%%%%%%%%  
    %%%%%%%%%%%%%%%%   %%%%%%%%%%%%%%   
    %%%%%%%%%%%%% %%%  %%%%%%%%%%%%%    
    #%%%%%%%%%%#  #%%  %%%%%%%%%%%#     
     ##%%%%%%%%%       %%%%%%%%%#       
       %% %%%%#      %%%%%%%%#          
         #%%%%%%%%%%%%%%%               
         %%%%%%%%%%%%%                  
       
endef
export SUPERSONIC

BLUE	=	$'\x1b[34m

RED   = $'\x1b[31m

YELLOW = $'\x1b[33m

NAME	=	so_long

BONUS = so_long_bonus

CC		=	cc

CFLAGS	=	-Wall -Werror -Wextra

SRCS 	= mand/so_long.c \
	mand/parsing_map.c \
    mand/parsing_utils.c \
    mand/valid_path.c \
	mand/rendering.c \
    mand/game.c \
    mand/game_ending.c \
    mand/checkimages.c \

BONUS_SRCS  = bonus/so_long.c \
		    bonus/parsing_map.c \
            bonus/parsing_utils.c \
            bonus/valid_path.c \
		    bonus/rendering.c \
            bonus/game.c \
            bonus/game_ending.c \
            bonus/dash.c \
            bonus/check_images.c \
            bonus/update.c \
            bonus/destroy.c \
            bonus/getpictures.c \
            bonus/enemies_and_extras.c

OBJS	=	$(SRCS:.c=.o)

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

LIBFT	=	libft/libft.a

PRINTF	=	ft_printf/libftprintf.a

# ifeq (${OS}, Darwin)
#   MLXDIR = mlx
#   MLX = ${MLXDIR}/libmlx.a
#   MLXFLAG = -L$(MLXDIR) -lmlx -framework OpenGL -framework Appkit -L/usr/lib -lm
# else ifeq (${OS}, Linux)
#   MLXDIR = minilibx_linux
#   MLX = minilibx_linux/libmlx.a
#   MLXFLAG = -L minilibx_linux -lmlx -L/usr/lib -lXext -lX11 -lm -lGL
# endif

UNAME := $(shell uname -s)

ifeq ($(UNAME), Darwin)
  MLXDIR = mlx
  MLX = mlx/libmlx.a
  MLXFLAG = -Lmlx -lmlx -framework OpenGL -framework Appkit -L/usr/lib -lm
  # MLXFLAG = -lmlx
else ifeq ($(UNAME), Linux)
  MLXDIR = minilibx_linux
  MLX = minilibx_linux/libmlx_Linux.a
  MLXFLAG = -L minilibx_linux -lmlx -L/usr/lib -lXext -lX11 -lm -lGL
endif

# $(MLX):
# 	$(MAKE) -C $(MLXDIR)


# MLXDIR = minilibx_linux
# MLX = minilibx_linux/libmlx.a
# MLXFLAG = -L minilibx_linux -lmlx -L/usr/lib -lXext -lX11 -lm -lGL

all		:	$(NAME)

$(LIBFT):
	@$(MAKE)	-C libft

$(PRINTF):
	@$(MAKE)	-C ft_printf

$(MLX):
	@$(MAKE)  -C $(MLXDIR)

	
$(NAME)	: $(OBJS) $(LIBFT)  $(MLX)  $(PRINTF)
	@$(CC) $(CFLAGS) $(OBJS) $(MLXFLAG) -o $@ $(LIBFT) $(MLX) $(PRINTF)
	@ echo "${BLUE}$$SONIC"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@


bonus	: $(BONUS)

$(BONUS) 	: $(BONUS_OBJS) $(LIBFT) $(MLX) $(PRINTF)
	@$(CC) $(CFLAGS) $(BONUS_OBJS) $(MLXFLAG) -o $@ $(LIBFT) $(MLX) $(PRINTF)
	@rm -f $(NAME)
	@rm -f $(OBJS)
	@ echo "${YELLOW}$$SUPERSONIC"

clean :
	@$(MAKE) -C libft clean
	@$(MAKE) -C ft_printf clean
	@rm -f $(OBJS)
	@rm -f $(BONUS_OBJS)
		
fclean: clean
	@$(MAKE) -C libft fclean
	@$(MAKE) -C ft_printf fclean
	@$(MAKE) -C $(MLXDIR) clean
	@ echo "${RED}$$SONIC"
	@rm -f $(NAME)
	@rm -f $(BONUS)

re:	fclean all
 
.PHONY: all clean fclean re bonus