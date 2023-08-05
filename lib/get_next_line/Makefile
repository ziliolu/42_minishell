NAME = get_next_line.a
OBJ = $(SRC:.c=.o)
CC = cc
CFLAGS = -Wall -Werror -Wextra
AR = ar rcs 
RM = rm -f

SRC = ./get_next_line.c\
	./get_next_line_utils.c\

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

clean: 
	$(RM) $(OBJ) $(NAME)

fclean: clean 
	$(RM) $(NAME)
	
re: fclean all

.PHONY: clean fclean re