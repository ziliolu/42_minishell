NAME = minishell
LIB = lib.a

CC = cc 
CFLAGS = -Wextra -Werror -Wall -g -I./includes 
RM = rm -f 

LIBDIR = ./lib/
SRC =	./src/*.c			\
		./src/builtins/*.c	\
		./src/utils/*.c		\

all: $(NAME) 

$(NAME): $(OBJ) $(LIB)
	$(CC) $(CFLAGS) $(SRC) $(LIBDIR)$(LIB) -lreadline -o $(NAME) 

$(LIB):
	make -C lib

clean: 
	make clean -C lib
	$(RM) $(OBJ)

fclean: clean 
	$(RM) $(NAME)

re: clean all