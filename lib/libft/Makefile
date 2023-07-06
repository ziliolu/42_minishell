# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/25 09:29:52 by lpicoli-          #+#    #+#              #
#    Updated: 2023/07/06 21:52:43 by ialves-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC =	./ft_atoi.c 		\
 		./ft_bzero.c		\
		./ft_calloc.c		\
 		./ft_isalnum.c 		\
 		./ft_isalpha.c 		\
 		./ft_isascii.c 		\
 		./ft_isdigit.c 		\
		./ft_isprint.c 		\
		./ft_itoa.c 		\
 		./ft_memchr.c 		\
 		./ft_memcmp.c 		\
 		./ft_memcpy.c 		\
 		./ft_memmove.c 		\
 		./ft_memset.c 		\
 		./ft_putchar_fd.c 	\
 		./ft_putendl_fd.c 	\
 		./ft_putnbr_fd.c 	\
 		./ft_putstr_fd.c 	\
		./ft_split.c		\
		./ft_strchr.c		\
		./ft_strdup.c		\
		./ft_striteri.c		\
		./ft_strjoin.c		\
		./ft_strlcat.c		\
		./ft_strlcpy.c		\
		./ft_strlen.c		\
		./ft_strmapi.c		\
		./ft_strncmp.c		\
		./ft_strnstr.c		\
		./ft_strrchr.c		\
		./ft_strtrim.c		\
		./ft_substr.c		\
		./ft_tolower.c		\
		./ft_toupper.c		\

OBJ = $(SRC:.c=.o)                                                                                                                                                                                                 
OBJ_BONUS = $(SRC_BONUS:.c=.o)                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
CC = cc -Wall -Wextra -Werror

all: $(NAME)                                                                                                                                                                                                       
                                                                                                                                                                                                                   
$(NAME):	$(OBJ) $(OBJ_BONUS) 
		ar rcs $(NAME) $(OBJ) $(OBJ_BONUS)

clean:                                                                                                                                                                                                             
		rm -rf $(OBJ) $(OBJ_BONUS)                                                                                                                                                                                             
                                                                                                                                                                                                                   
fclean: clean                                                                                                                                                                                                      
		rm -rf $(NAME) 

re: fclean all                                                                                                                                                                                                     
                                                                                                                                                                                                                   
