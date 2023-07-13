/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:36:28 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/13 17:31:25 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H

# include <readline/readline.h>
# include <readline/history.h>
# include <sys/types.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>
# include <sys/wait.h>
# include "../lib/libft/libft.h"
# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h>


typedef struct s_lst
{
    char 		*name;
	char 		*info;
    char 		*full_info;
    struct s_lst *next;
}	t_lst;

//extern t_lst **ms_env; 

extern int g_exit_status;

enum e_token
{
	WORD = 'w',
	WHITE_SPACE = ' ',
	NEW_LINE = '\n',
	SINGLE_QUOTE = '\'',
	DOUBLE_QUOTE = '\"',
	ESCAPE = '\\',
	ENV = '$',
	PIPE_LINE = '|',
	REDIR_IN = '<',
	REDIR_OUT = '>',
	HERE_DOC,
	D_REDIR_OUT,
	CMD,
};

// typedef struct s_var
// {
// 	char *name;
// 	char *info;
// 	struct s_var *next;	
// }				t_lst;

enum e_status
{
	IN_DQUOTE,
	IN_SQUOTE,
	GENERAL,
};

typedef struct s_elem
{
    char 		*data;
    int 		len;
    enum e_token type;
    enum e_status status;
    struct s_elem *next;
}	t_elem;

typedef struct s_pipe
{
	struct s_elem *right_command;
	struct s_elem *left_command;
}	t_pipe;

typedef struct s_redirect
{
	char 		*arg; //file name or eof (heredoc)
	enum e_token type;
}	t_redirect;

typedef struct s_command
{
	char 		**args;
	int 		in;
	int 		out;
	int 		fd[2];
	t_redirect 	*redirs;
	enum e_token operator;
	enum e_token type;
}	t_command;

typedef struct s_ms
{
	t_lst		*ms_env;
	char 		**ms_env_array;
	t_elem		**lexed_list;
    char 		**paths;
    char 		**system_env;
    char 		**ms_argv;
	int			*count_args;
	int 		read_size;
	int 		n_pipes; 
	int			std_in;
	int 		std_out;
	t_lst		**vars;
	t_command 	*cmds;
	t_pipe 		*pipes;
	int			is_print;
	int 		print_cmd;
	int			exit_status;
	bool		dot_comma_flag;
	int			spaces_flag;
}	t_ms;

// ==== utils ====
char		*ft_strndup(char *str, int n);
int			ft_strcmp(char *s1, char *s2);
void		ft_run_command(char *command, char **env);
void		ft_create_env(t_ms *ms, char **env);

//-----> ft_env functions <-----//
t_lst		*ft_new_node(char *str);
t_lst		*ft_find_last(t_lst *list);
char		*ft_get_list_name(char *set);
char		*ft_get_list_info(char *set);
void		ft_add_node(t_lst **header, char *str);
void		ft_print_list(t_lst *list);

bool		ft_is_executable(t_ms *ms, t_command *cmd);
bool		ft_is_absolute_path(char *input);
char		*ft_getenv(t_ms *ms, char *name);
void		ft_init_ms(t_ms *ms, char **system_env);

//-----> ft_is_arg_valid functions <-----//
bool        ft_is_arg_valid(t_ms *ms, char *read_content);
bool        ft_is_quote_valid(char *read_content);
bool        ft_is_valid_character(char c);
char        ft_choose_quotes(int s_quote, int d_quote);

bool		ft_is_variable(t_ms *ms);
bool		ft_is_valid_info(t_ms *ms, int j);
char        *ft_search_for_end(char *str, char c, int pos); 
char		*ft_charjoin(char *str, char c);

//-------> Free Memory <-------------//
void		ft_free_array(char **array);
void		ft_free_env(t_ms *ms);
void 		ft_free_cmds(t_ms *ms);
void		ft_free_memory(t_ms *ms);
void		ft_free_elem_list(t_elem *head);

t_elem		*ft_new_elem(char *str, int len, enum e_token type, enum e_status);
t_elem		*ft_find_last_elem(t_elem *list);
bool		ft_is_not_redir(enum e_token type);
bool 		ft_is_redir(enum e_token type);
bool 		ft_is_redir(enum e_token type);
bool		ft_is_there_quote(char *str);
char		*ft_token_status(enum e_status status);
char		*ft_token_type(enum e_token type);
char		*ft_expand(t_lst *list, t_lst *vars, char *variable);
char 		*ft_token_status(enum e_status status);
char		**ft_list_to_array(t_ms *ms);
char 		*ft_token_type(enum e_token type);
char		*ft_return_env_info(t_ms *ms, char *name);
char 		*ft_strtrim_end(char *str, char set);
int			ft_size_list(t_elem **header);
int			ft_count_char(char *str);
int			ft_count_pipes(t_elem *list);
int			ft_count_tokens(t_elem *list);
int 		ft_count_cmds(t_ms *ms);
int 		ft_count_redirs(t_elem *list);
int 		ft_count_redirs_cmd(t_command *cmd);
int			ft_count_pipes(t_elem *list);
void		ft_add_new_elem(t_elem **head, t_elem *new_elem);
void		ft_lexer(t_ms *ms, char *read_content);
void		ft_parser(t_ms *ms, t_elem *list);
void		ft_initialize_pipes(t_ms *ms, int nbr_of_pipes);
void		ft_print_command_nodes(t_ms *ms, int n_pipes);
void		ft_print_tokens(t_ms *ms, t_elem *list);
void 		ft_run_cmds(t_ms *ms);
void 		ft_is_heredoc(t_command *cmd, t_redirect *redir);
void 		ft_pipeline(t_ms *ms);
void 		ft_init_pipes(t_ms *ms);
void		ft_handle_signals();
void		ft_filter_cmd(t_ms *ms, t_command *cmd);
void        ft_cd(t_ms *ms, t_command *cmd);
void		ft_update_env(t_ms *ms, char *name, char *new_info);
char		*ft_return_env_info(t_ms *ms, char *name);
bool		ft_is_there_quote(char *str);
char 		*ft_strtrim_end(char *str, char set);
void		ft_count_args(t_ms *ms, t_elem *list);
char		**ft_list_to_array(t_ms *ms);
void		ft_print_array(char **str);
void		ft_add_local_variable(t_lst **head, char *name, char *info);
char		*ft_strchr_vars(char *s, char c);
bool		ft_change_standard_in_out(t_command *cmd);
void		ft_reset_fd_in_out(t_ms *ms);
void		ft_echo(t_command *cmd);
void		ft_print_local_variables(t_lst **head);
void		ft_update_list_info(t_lst *list, char *name, char *info);
bool		ft_is_already_in_list(char *name, t_lst *list);
void		ft_export(t_ms *ms, t_command *cmd);
char		*ft_return_list_info(t_lst *lst, char *name);
void		ft_add_node_to_list(t_ms *ms, t_lst **head, char *str);
char		*ft_return_list_full_info(t_lst *lst, char *name);
t_lst		*ft_find_second_to_last(t_lst **head);
void		ft_add_export_node(t_lst **header, char *str);
void 		ft_remove_node_list(t_lst **head, char *name);
void    	ft_print_export(t_lst *lst);
void		ft_update_list(t_lst *list, char *name, char *new_info);
char		*ft_broken_cmds(t_ms *ms, char *str);
int 		ft_count_char_env(char *str);
int			ft_valid_env(char c);
bool		ft_is_dot_comma(char *str);
bool		ft_arg_exist(char *arg);
bool 		ft_error(t_ms *ms, char *msg, char *str);
bool ft_cmd_args_validation(t_ms *ms);
void ft_unset(t_ms *ms);
void ft_exit(t_ms *ms);
bool ft_error_var_start(char *msg, char *str);
void ft_handler_loop(int signal);
void ft_handle_signals_loop();
char *ft_strtrim_end_quote(char *str, char set);

#endif
