NAME = minishell
LIB = lib.a

CC = cc 
CFLAGS = -Wextra -Werror -Wall -g -I./includes #-fsanitize=address
RM = rm -f 

LIBDIR = ./lib/
SRC =	./src/*.c			\
		./src/builtins/*.c	\
		./src/utils/*.c		\
		./src/builtins/env/*.c 	\
		./src/pipes/*.c			\
		./src/lexer/*.c			\
		./src/parser/*.c		\
		./src/print/*.c			\
		./src/redirect/*.c		\
		./src/executable/*.c

COLOUR_RED = 		\e[31m
COLOUR_ORANGE_B = 	\e[91m
COLOUR_ORANGE_L = 	\e[33m
COLOUR_YELLOW = 	\e[93m
COLOUR_GREEN_B = 	\e[32m
COLOUR_GREEN_L = 	\e[92m
COLOUR_BLUE_B =		\e[34m
COLOUR_BLUE_L =		\e[94m


all: $(NAME) 
	@echo "$(COLOUR_RED)    __  ________   ___________ __  __________    __ ";
	@echo "$(COLOUR_ORANGE_B)   /  |/  /  _/ | / /  _/ ___// / / / ____/ /   / / ";
	@echo "$(COLOUR_YELLOW)  / /|_/ // //  |/ // / \__  / /_/ / __/ / /   / /  ";
	@echo "$(COLOUR_GREEN_L) / /  / // // /|  // / ___/ / __  / /___/ /___/ /___";
	@echo "$(COLOUR_BLUE_L)/_/  /_/___/_/ |_/___//____/_/ /_/_____/_____/_____/";
	@echo "$(COLOUR_BLUE_B)******* Project made by: ipicoli && ialves-i *******";


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