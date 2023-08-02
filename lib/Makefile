NAME = lib.a
SRCS =  ./libft/ft_isalpha.c\
		./libft/ft_strjoin.c\
		./libft/ft_toupper.c\
		./libft/ft_striteri.c\
		./libft/ft_isascii.c\
		./libft/ft_strlcat.c\
		./libft/ft_memcmp.c\
		./libft/ft_putchar_fd.c\
		./libft/ft_strnstr.c\
		./libft/ft_strlcpy.c\
		./libft/ft_isdigit.c\
		./libft/ft_strlen.c\
		./libft/ft_itoa.c\
		./libft/ft_putstr_fd.c\
		./libft/ft_atoi.c\
		./libft/ft_putendl_fd.c\
		./libft/ft_strdup.c\
		./libft/ft_strchr.c\
		./libft/ft_strmapi.c\
		./libft/ft_isalnum.c\
		./libft/ft_strncmp.c\
		./libft/ft_calloc.c\
		./libft/ft_bzero.c\
		./libft/ft_memchr.c\
		./libft/ft_memset.c\
		./libft/ft_strrchr.c\
		./libft/ft_memcpy.c\
		./libft/ft_memmove.c\
		./libft/ft_atoll.c\
		./libft/ft_tolower.c\
		./libft/ft_split.c\
		./libft/ft_putnbr_fd.c\
		./libft/ft_strtrim.c\
		./libft/ft_substr.c\
		./libft/ft_isprint.c\
		./get_next_line/get_next_line.c\
		./get_next_line/get_next_line_utils.c\
		./printf/ft_putstr.c\
		./printf/ft_puthexa.c\
		./printf/ft_put_unsigned.c\
		./printf/ft_putchar.c\
		./printf/ft_counter.c\
		./printf/ft_hexlen.c\
		./printf/ft_putnbr.c\
		./printf/ft_printf.c\
		./printf/ft_filter_format.c\
		./printf/ft_putptr.c

CC = cc
CFLAGS = -Wextra -Werror -Wall

OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))
AR = ar rcs


all: $(NAME)

vpath %.c ./libft ./get_next_line ./printf


$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

# Rule to compile source files into object files
$(OBJ_DIR)/%.o: %.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_DIR)/*.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re