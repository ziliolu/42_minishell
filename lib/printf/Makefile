NAME = libftprintf
OBJ = $(SRC:.c=.o)
CC = cc 
CFLAGS = -Wall -Wextra -Werror

SRC =	./ft_filter_format.c\
		./ft_hexlen.c\
		./ft_printf.c\
		./ft_putchar.c\
		./ft_puthexa.c\
		./ft_putnbr.c\
		./ft_putstr.c\
		./ft_putptr.c\
		./ft_put_unsigned.c\
		./ft_counter.c\

all: $(NAME)

vpath %.c ./libft ./get_next_line ./printf

$(NAME): $(OBJ)
	ar rcs	$(NAME) $(OBJ)

clean:
	rm -rf $(OBJ) $(NAME)

fclean: clean
	rm -rf $(NAME)

re: fclean all
