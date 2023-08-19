NAME = minishell
LIBDIR = ./lib/
LIB = lib.a
OBJ = $(SRC:.c=.o)
CC = cc
CFLAGS = -Wextra -Werror -Wall -g -I./includes
RM = rm -f 

SRC = ./src/run/ft_filter_cmd_else.c\
	./src/run/ft_count_cmds.c\
	./src/run/init_ms.c\
	./src/run/ft_change_standard_in_out.c\
	./src/run/ft_wait.c\
	./src/run/ft_filter_cmd.c\
	./src/run/ft_run_cmds.c\
	./src/run/ft_main_cycle.c\
	./src/run/ft_reset_fd_in_out.c\
	./src/run/ft_connect_pipes.c\
	./src/run/ft_main_cycle_read.c\
	./src/pipes/ft_init_pipes.c\
	./src/pipes/ft_broken_cmds.c\
	./src/pipes/ft_input_is_pipe.c\
	./src/pipes/ft_close_pipes.c\
	./src/pipes/ft_count_pipes.c\
	./src/pipes/ft_is_broken_cmds_pipe.c\
	./src/signals/ft_handle_signals.c\
	./src/signals/ft_signals_heredoc.c\
	./src/signals/ft_handle_signals_loop.c\
	./src/signals/ft_handler.c\
	./src/signals/ft_handler_loop.c\
	./src/signals/ft_signals_ignore.c\
	./src/utils/validations/ft_is_variable.c\
	./src/utils/validations/ft_if_readline_is_valid.c\
	./src/utils/validations/ft_redirs_validation_while.c\
	./src/utils/validations/ft_is_valid_character.c\
	./src/utils/validations/ft_is_valid_info.c\
	./src/utils/validations/ft_cmd_args_validation.c\
	./src/utils/validations/ft_is_arg_valid.c\
	./src/utils/validations/ft_pipe_validation.c\
	./src/utils/validations/ft_is_valid_number.c\
	./src/utils/validations/ft_arg_exist.c\
	./src/utils/validations/ft_is_quote_valid.c\
	./src/utils/validations/ft_is_quote_valid_msg.c\
	./src/utils/validations/ft_is_valid_env_name.c\
	./src/utils/validations/ft_if_valid_info_is_squote.c\
	./src/utils/validations/ft_if_valid_info_is_dquote.c\
	./src/utils/validations/ft_redirs_validation.c\
	./src/utils/general/ft_strtrim_end_quote.c\
	./src/utils/general/ft_strjoin_wo_leaks.c\
	./src/utils/general/ft_chartrim_wo_dquotes.c\
	./src/utils/general/ft_env_to_array.c\
	./src/utils/general/ft_is_dot_comma.c\
	./src/utils/general/ft_is_not_read_content.c\
	./src/utils/general/ft_char_join.c\
	./src/utils/general/ft_format_slash.c\
	./src/utils/general/ft_strtrim_end.c\
	./src/utils/general/ft_choose_quotes.c\
	./src/utils/general/ft_strndup.c\
	./src/utils/general/ft_chartrim_w_dquotes.c\
	./src/utils/general/ft_strchr_vars.c\
	./src/utils/general/ft_is_export_type.c\
	./src/utils/general/ft_is_there_quote.c\
	./src/utils/general/ft_is_there_space.c\
	./src/utils/general/ft_env_to_array_while.c\
	./src/utils/general/ft_getcwd.c\
	./src/utils/general/ft_is_in_llong_range.c\
	./src/utils/general/ft_chartrim_wo_dquotes_while.c\
	./src/utils/general/ft_search_for_end.c\
	./src/utils/general/ft_chartrim_w_dquotes_while.c\
	./src/utils/general/ft_strcmp.c\
	./src/utils/list_utils/ft_add_node.c\
	./src/utils/list_utils/ft_getenv.c\
	./src/utils/list_utils/ft_remove_node_list_while.c\
	./src/utils/list_utils/ft_return_list_full_info.c\
	./src/utils/list_utils/ft_remove_node_list.c\
	./src/utils/list_utils/ft_find_last.c\
	./src/utils/list_utils/ft_get_list_name.c\
	./src/utils/list_utils/ft_find_second_to_last.c\
	./src/utils/list_utils/ft_get_list_info.c\
	./src/utils/list_utils/ft_update_list.c\
	./src/utils/list_utils/ft_is_already_in_list.c\
	./src/utils/list_utils/ft_return_list_info.c\
	./src/utils/list_utils/ft_add_export_node.c\
	./src/utils/list_utils/ft_add_node_to_list.c\
	./src/utils/list_utils/ft_new_node.c\
	./src/utils/free_memory/ft_free_env.c\
	./src/utils/free_memory/ft_free_node.c\
	./src/utils/free_memory/ft_free.c\
	./src/utils/free_memory/ft_free_elem_list.c\
	./src/utils/free_memory/ft_free_counters.c\
	./src/utils/free_memory/ft_free_cmds_while.c\
	./src/utils/free_memory/ft_free_cmds.c\
	./src/utils/free_memory/ft_free_memory.c\
	./src/utils/free_memory/ft_free_array.c\
	./src/lexer/ft_size_list.c\
	./src/lexer/ft_lexer.c\
	./src/lexer/ft_lexer_is_squote.c\
	./src/lexer/ft_token_type_else.c\
	./src/lexer/ft_token_status.c\
	./src/lexer/ft_lexer_if_str_redir_out.c\
	./src/lexer/ft_count_args_is_dquote.c\
	./src/lexer/ft_count_args.c\
	./src/lexer/ft_lexer_if_str_squote.c\
	./src/lexer/ft_add_new_elem.c\
	./src/lexer/ft_lexer_if_str_else.c\
	./src/lexer/ft_count_char.c\
	./src/lexer/ft_lexer_if_str_redir_in.c\
	./src/lexer/ft_find_last_elem.c\
	./src/lexer/ft_count_args_is_squote.c\
	./src/lexer/ft_lexer_if_while_str.c\
	./src/lexer/ft_new_elem.c\
	./src/lexer/ft_lexer_if_str_dquote.c\
	./src/lexer/ft_count_args_is_word.c\
	./src/lexer/ft_token_type.c\
	./src/lexer/ft_count_args_is_pipe.c\
	./src/lexer/ft_valid_env.c\
	./src/lexer/ft_count_char_env.c\
	./src/error/ft_error_var_start.c\
	./src/error/ft_error_wo_prompt.c\
	./src/error/ft_error.c\
	./src/main.c\
	./src/builtins/exit/ft_exit_is_cmd_arg.c\
	./src/builtins/exit/ft_exit.c\
	./src/builtins/exit/ft_exit_free.c\
	./src/builtins/exit/ft_exit_validation.c\
	./src/builtins/export/ft_export_is_in_env_list.c\
	./src/builtins/export/ft_export.c\
	./src/builtins/export/ft_export_is_cmd_arg.c\
	./src/builtins/export/ft_create_env_exp.c\
	./src/builtins/ft_unset.c\
	./src/builtins/ft_env.c\
	./src/builtins/cd/ft_cd_is_chdir.c\
	./src/builtins/cd/ft_cd.c\
	./src/builtins/cd/ft_cd_while_is_not_pwd.c\
	./src/builtins/cd/ft_cd_is_not_pwd.c\
	./src/builtins/cd/ft_cd_home_path.c\
	./src/builtins/echo/ft_echo.c\
	./src/builtins/echo/ft_echo_is_cmd_arg.c\
	./src/parser/ft_parser_while_dif_null.c\
	./src/parser/ft_is_in_double_quote_while.c\
	./src/parser/ft_parser_while_dif_pipe.c\
	./src/parser/ft_is_env_and_squote.c\
	./src/parser/ft_ptr_is_in_quotes.c\
	./src/parser/ft_parser_count_pipes.c\
	./src/parser/ft_is_in_single_quote.c\
	./src/parser/ft_is_redir_type.c\
	./src/parser/ft_expand_while_vars.c\
	./src/parser/ft_is_redir_single_quote.c\
	./src/parser/ft_expand_while_env.c\
	./src/parser/ft_is_env_in_quotes.c\
	./src/parser/ft_expand.c\
	./src/parser/ft_count_tokens.c\
	./src/parser/ft_parser.c\
	./src/parser/ft_is_in_double_quote.c\
	./src/parser/ft_parser_is_not_null.c\
	./src/parser/ft_is_redir_double_quote.c\
	./src/parser/ft_parser_is.c\
	./src/print/ft_print_local_variables.c\
	./src/print/ft_print_cmd_nodes_while_pipe.c\
	./src/print/ft_print_export.c\
	./src/print/ft_print_list.c\
	./src/print/ft_print_tokens.c\
	./src/print/ft_print_cmd_nodes.c\
	./src/print/ft_print_array.c\
	./src/executable/ft_is_executable.c\
	./src/executable/ft_join_old_w_new_pwd.c\
	./src/executable/ft_is_executable_while_path.c\
	./src/executable/ft_is_absolute_path.c\
	./src/executable/ft_is_home_path.c\
	./src/redirect/ft_is_ctrld_heredoc.c\
	./src/redirect/ft_is_redir.c\
	./src/redirect/ft_is_heredoc.c\
	./src/redirect/ft_open_redirs.c\
	./src/redirect/ft_is_heredoc_read_content.c\
	./src/redirect/ft_count_redirs_cmd.c\
	./src/redirect/ft_count_redirs.c\
	./src/redirect/ft_expand_heredoc.c\
	./src/redirect/ft_open_redirs_if_others.c\
	./src/redirect/ft_is_not_redir.c\
	./src/redirect/ft_join_heredoc_inputs.c\
	./src/redirect/ft_open_redirs_if_var.c\
	./src/redirect/ft_is_arg_redir.c\

COLOUR_RED = 		\e[31m
COLOUR_ORANGE_B = 	\e[91m
COLOUR_ORANGE_L = 	\e[33m
COLOUR_YELLOW = 	\e[93m
COLOUR_GREEN_B = 	\e[32m
COLOUR_GREEN_L = 	\e[92m
COLOUR_BLUE_B =		\e[34m
COLOUR_BLUE_L =		\e[94m

all: $(LIB) $(NAME) 
	@echo "$(COLOUR_RED)    __  ________   ___________ __  __________    __ ";
	@echo "$(COLOUR_ORANGE_B)   /  |/  /  _/ | / /  _/ ___// / / / ____/ /   / / ";
	@echo "$(COLOUR_YELLOW)  / /|_/ // //  |/ // / \__  / /_/ / __/ / /   / /  ";
	@echo "$(COLOUR_GREEN_L) / /  / // // /|  // / ___/ / __  / /___/ /___/ /___";
	@echo "$(COLOUR_BLUE_L)/_/  /_/___/_/ |_/___//____/_/ /_/_____/_____/_____/";
	@echo "$(COLOUR_BLUE_B)******* Project made by: lpicoli && ialves-i *******";

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -L$(LIBDIR) -l:$(LIB) -lreadline -o $(NAME)

$(LIB):
	@$(MAKE) -s -C $(LIBDIR)

ifeq ($(wildcard $(LIBDIR)$(LIB)),)
$(LIBDIR)$(LIB):
	make -s -C $(LIBDIR)
else ifeq ($(shell find $(LIBDIR)$(LIB) -newer $(NAME) -print -quit),)
$(LIBDIR)$(LIB):
	make -s -C $(LIBDIR)
endif

clean: 
	make clean -C $(LIBDIR)
	$(RM) $(OBJ)

fclean: clean 
	$(RM) $(NAME) $(OBJ)

fast: fclean
	$(MAKE) -j

.NOTPARALEL: re
re: clean all

.PHONY: clean fclean re
