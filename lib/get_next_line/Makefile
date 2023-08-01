NAME = get_next_line.a

SRC =			./get_next_line.c				\
				./get_next_line_utils.c 		\

SRC_BONUS = 	./get_next_line_bonus.c			\
				./get_next_line_utils_bonus.c	\

OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)
CC = cc
CFLAGS = -Wall -Werror -Wextra
AR = ar rcs 
RM = rm -f

all: $(NAME)

$(NAME): $(OBJ) $(OBJ_BONUS)
	$(AR) $(NAME) $(OBJ) $(OBJ_BONUS)

bonus: $(OBJ_BONUS)
	$(AR) $(NAME) $(OBJ_BONUS)
	
clean: 
	$(RM) $(OBJ) $(OBJ_BONUS)

fclean: clean 
	$(RM) $(NAME)
	
re: fclean all 