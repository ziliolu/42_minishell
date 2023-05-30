NAME = lib.a
SRCS = $(shell find . -name '*.c')
CFLAGS = -Wextra -Werror -Wall
OBJ = $(SRCS:.c=.o)
AR = ar rcs 

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

clean: $(OBJ)
	rm -f $(OBJ)

fclean: clean 
	rm -f $(NAME)

re: fclean all