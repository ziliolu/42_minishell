LIB = lib.a
AR = ar rcs

# Lista de arquivos objeto para cada biblioteca
GET_NEXT_LINE_OBJ = get_next_line/*.o
LIBFT_OBJ = libft/*.o
PRINTF_OBJ = printf/*.o

all:
	$(MAKE) -C ./get_next_line/
	$(MAKE) -C ./libft/
	$(MAKE) -C ./printf/
	$(AR) $(LIB) $(GET_NEXT_LINE_OBJ) $(LIBFT_OBJ) $(PRINTF_OBJ)

clean:
	$(MAKE) -C ./get_next_line clean
	$(MAKE) -C ./libft clean
	$(MAKE) -C ./printf clean
	rm -f $(LIB)

fclean: clean

re: fclean all

.PHONY: fclean re all clean
