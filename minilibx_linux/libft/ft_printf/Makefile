NAME = libftprintf.a

SRCS = ft_printf.c ft_concoct.c ft_putchar.c ft_puthex.c ft_putnbr.c ft_putptr.c ft_putstr.c ft_putusd.c

OBJS = $(SRCS:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJS)
	ar -rcs $@ $^

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME) 

re : fclean all

.PHONY : all clean fclean re