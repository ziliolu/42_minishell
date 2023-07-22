/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:36:28 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/23 00:15:03 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H


# include "../lib/libft/libft.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/types.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>
# include <sys/wait.h>
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
	int			pid;
	int			status;
	t_redirect 	*redirs;
	bool		err;
	enum e_token operator;
	enum e_token type;
}	t_command;

typedef struct s_counters
{
	int		i;
	int		j;
	int		k;
	char	*str;
	char	*tmp_str;
	char	*tmp_arg;
	t_elem	*list;
}	t_counters;

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
	int			pid;
	int			status;
	int			processes;
	int			atoi_tmp;
	int			i;
	int			j;
	int			go_out;
}	t_ms;

typedef struct s_cd
{
	char	*pwd;
	char	*oldpwd;
	char	*path;
	char	*tmp;
	char	*tmp_path;
	char	*tmp_path_w_slash;
	int		i;
}	t_cd;

typedef struct s_export
{
	char	*name;
	char	*info;
	char	*str;
	int		i;
}	t_export;

typedef struct s_echo
{
	char	*tmp;
	char	*final;
	char	*str;
	int		i;
}	t_echo;

typedef struct s_lexer
{
    int		squote_flag;
    int		dquote_flag;
    int		i;
}	t_lexer;

typedef struct s_broken_cmds
{
	int		size;
	char	*prompt;
	char	*prompt_tmp;
    char	*new_str;
	char	*tmp;
}	t_broken_cmds;

typedef struct s_heredoc
{
	char	*eof;
	char	*str;
	int		fd;
	int		fd2;
	char	*read_content;
	char	*prompt;
}	t_heredoc;

// A
void		ft_add_node_to_list(t_ms *ms, t_lst **head, char *str);
void		ft_add_node(t_lst **header, char *str);
void		ft_add_new_elem(t_elem **head, t_elem *new_elem);
void		ft_add_node_to_list(t_ms *ms, t_lst **head, char *str);
void		ft_add_export_node(t_lst **header, char *str);
bool		ft_arg_exist(char *arg);

// B
char		*ft_broken_cmds(t_ms *ms, char *str);
char	*ft_is_broken_cmds_pipe(t_ms *ms, char *str, t_broken_cmds *b);

// C
void		ft_create_env(t_ms *ms, char **env);
char        ft_choose_quotes(int s_quote, int d_quote);
char		*ft_charjoin(char *str, char c);
int			ft_count_char(char *str);
int			ft_count_pipes(t_elem *list);
int			ft_count_tokens(t_elem *list);
int 		ft_count_cmds(t_ms *ms);
int 		ft_count_redirs(t_elem *list);
int 		ft_count_redirs_cmd(t_command *cmd);
int			ft_count_pipes(t_elem *list);
void        ft_cd(t_ms *ms, t_command *cmd);
void		ft_count_args(t_ms *ms, t_elem *list);
bool		ft_change_standard_in_out(t_command *cmd);
int 		ft_count_char_env(char *str);
bool 		ft_cmd_args_validation(t_ms *ms);
void 		ft_close_pipes(t_ms *ms);
char		*ft_chartrim_wo_dquotes(char *str, char c);
char		*ft_chartrim_w_dquotes(char *str, char c);
char		*ft_charjoin(char *str, char c);
void		ft_cd_is_chdir(t_ms *ms, t_command *cmd, t_cd *cd);
t_elem		*ft_count_args_is_squote(t_ms *ms, t_elem *list);
t_elem		*ft_count_args_is_dquote(t_ms *ms, t_elem *list);
t_elem		*ft_count_args_is_pipe(t_ms *ms, t_elem *list);
t_elem		*ft_count_args_is_word(t_ms *ms, t_elem *list);
int		ft_count_redirs_cmd(t_command *cmd);
void	ft_connect_pipes(t_ms *ms, t_counters *c);



// E
void		ft_echo(t_command *cmd);
void		ft_echo_is_cmd_arg(t_command *cmd, t_echo *echo);
void		ft_env(t_command *cmd, t_lst *lst);
bool 		ft_error(t_ms *ms, char *msg, char *str);
bool 		ft_error_var_start(char *msg, char *str, int err_number);
void		ft_export(t_ms *ms, t_command *cmd);
void		ft_export_is_cmd_arg(t_ms *ms, t_command *cmd, int i);
void		ft_export_is_in_env_list(t_ms *ms, t_command *cmd, t_export *exp);
bool		ft_executable_is_access(t_ms *ms, t_command *cmd, char *total_path, char *path_w_slash);
void 		ft_exit(t_ms *ms, t_command *cmd);
void		ft_exit_free(t_ms *ms);
char		*ft_exit_is_cmd_arg(t_ms *ms, t_command *cmd, char *tmp);
char		*ft_expand(t_lst *list, t_lst *vars, char *variable);
char	*ft_expand_while_env(t_lst *env, t_lst *vars, char *str);
char	*ft_expand_while_vars(t_lst *env, t_lst *vars, char *str);

// F
t_lst		*ft_find_last(t_lst *list);
void		ft_free_array(char **array);
void		ft_free_env(t_ms *ms);
void 		ft_free_cmds(t_ms *ms);
void		ft_free_memory(t_ms *ms);
void		ft_free_elem_list(t_elem *head);
void 		ft_free_counters(t_counters *c);
void 		ft_free(char *str);
void		ft_free_node(t_lst *node);
t_elem		*ft_find_last_elem(t_elem *list);
void		ft_filter_cmd(t_ms *ms, t_command *cmd);
void		ft_filter_cmd_else(t_ms *ms, t_command *cmd);
t_lst		*ft_find_second_to_last(t_lst **head);

// G
char		*ft_get_list_name(char *set);
char		*ft_get_list_info(char *set);
char		*ft_getenv(t_ms *ms, char *name);

// H
void		ft_handle_signals();
void 		ft_handler_loop(int signal);
void 		ft_handle_signals_loop();

// I
bool 		ft_is_home_path(char *str);
void		ft_init_ms(t_ms *ms, char **system_env);
void 		ft_init_pipes(t_ms *ms);
bool		ft_is_absolute_path(char *input);
bool        ft_is_arg_valid(t_ms *ms, char *read_content);
bool		ft_is_already_in_list(char *name, t_lst *list);
bool 		ft_is_arg_redir(char *arg);
bool		ft_is_absolute_path(char *str);
bool		ft_is_dot_comma(char *str);
bool		ft_is_executable(t_ms *ms, t_command *cmd);
bool 		ft_is_export_type(char *str);
void		ft_is_env_and_squote(t_ms *ms, t_counters *p);
void 		ft_is_heredoc(t_command *cmd, t_redirect *redir);
char	*ft_is_heredoc_read_content(t_command *cmd, t_heredoc *h);
void		ft_is_in_single_quote(t_ms *ms, t_counters *p);
void		ft_is_in_double_quote_while(t_ms *ms, t_counters *p);
void		ft_is_in_double_quote(t_ms *ms, t_counters *p);
void		ft_is_not_read_content(t_ms *ms, char *read_content);
bool		ft_is_not_redir(enum e_token type);
bool        ft_is_quote_valid(char *read_content);
void		ft_if_readline_is_valid(t_ms *ms, char *read_content);
bool 		ft_is_redir(enum e_token type);
void		ft_is_redir_single_quote(t_ms *ms, t_counters *p);
void		ft_is_redir_double_quote(t_ms *ms, t_counters *p);
void		ft_is_redir_type(t_ms *ms, t_counters *p);
bool		ft_is_there_quote(char *str);
bool 		ft_is_there_space(char *str);
bool        ft_is_valid_character(char c);
bool		ft_is_variable(t_ms *ms);
bool		ft_is_valid_character(char character);
bool		ft_is_variable(t_ms *ms);
bool		ft_is_valid_info(t_ms *ms, int j);
void		ft_if_valid_info_is_squote(t_ms *ms, int j, char *str, char *var_info);
void		ft_if_valid_info_is_dquote(t_ms *ms, int j, char *str, char *var_info);
void		ft_is_not_pwd(t_ms *ms, t_command *cmd, t_cd *cd);
void	ft_is_env_in_quotes(t_counters *p, char *exp_or_data, char *tmp_str);
void	ft_is_executable_while_path(t_ms *ms, t_command *cmd, char *path_w_slash, char *total_path);

// L
char		**ft_list_to_array(t_ms *ms);
char		**ft_list_to_array(t_ms *ms);
void		ft_lexer(t_ms *ms, char *read_content);
// void		ft_lexer_is_squote(t_lexer *x, t_elem **elem_head, char *str, enum e_status status);
void		ft_lexer_if_str_squote(t_lexer *x, t_elem **elem_head, char *str, enum e_status status);
void		ft_lexer_if_str_dquote(t_lexer *x, t_elem **elem_head, char *str, enum e_status status);
void		ft_lexer_if_str_redir_in(t_lexer *x, t_elem **elem_head, char *str, enum e_status status);
void		ft_lexer_if_str_redir_out(t_lexer *x, t_elem **elem_head, char *str, enum e_status status);
void		ft_lexer_if_str_else(t_lexer *x, t_elem **elem_head, char *str, enum e_status status);
void		ft_lexer_if_while_str(t_lexer *x, t_elem **elem_head, char *str, enum e_status status);


// M
void		ft_main_cycle(t_ms *ms, char *read_content, char *tmp_prompt, char *prompt);

// N
t_lst		*ft_new_node(char *str);
t_elem		*ft_new_elem(char *str, int len, enum e_token type, enum e_status);


// O
bool	ft_open_redirs(t_ms *ms, t_counters *c);
bool	ft_open_redirs_if_var(t_ms *ms, t_counters *c, char *tmp_arg);
bool	ft_open_redirs_if_others(t_ms *ms, t_counters *c);

// P
bool		ft_pipe_validation(t_ms *ms);
void		ft_print_list(t_lst *list);
void		ft_print_command_nodes(t_ms *ms, int n_pipes);
void	ft_print_command_nodes_while_pipe(t_ms *ms, int i, int j, int k);
void		ft_print_tokens(t_ms *ms, t_elem *list);
void		ft_print_array(char **str);
void		ft_print_local_variables(t_lst **head);
void    	ft_print_export(t_lst *lst);
void		ft_parser_count_pipes(t_ms *ms, t_counters *p);
void		ft_parser(t_ms *ms, t_elem *list);
void		ft_parser_while_dif_pipe(t_ms *ms, t_counters *p, int c);
void		ft_parser_while_dif_null(t_ms *ms, t_counters *p, int c);
void		ft_parser_is(t_ms *ms, t_counters *p);
void	ft_parser_is_not_null(t_ms *ms, t_counters *p, char *tmp_arg, char *tmp_list);
void		ft_ptr_is_in_quotes(t_ms *ms, t_counters *p);

// R
void 		ft_run_cmds(t_ms *ms);
bool		ft_redirs_validation(t_ms *ms);
void		ft_reset_fd_in_out(t_ms *ms);
char		*ft_return_list_info(t_lst *lst, char *name);
char		*ft_return_list_full_info(t_lst *lst, char *name);
void 		ft_remove_node_list(t_lst **head, char *name);

// S
char		*ft_strndup(char *str, int n);
int			ft_strcmp(char *s1, char *s2);
char        *ft_search_for_end(char *str, char c, int pos); 
char 		*ft_strtrim_end(char *str, char set);
int			ft_size_list(t_elem **header);
char 		*ft_strtrim_end(char *str, char set);
char		*ft_strchr_vars(char *s, char c);
char 		*ft_strtrim_end_quote(char *str, char set);
char		*ft_strjoin_wo_leaks(char* s1, char* s2);
char		*ft_search_for_end(char *str, char c, int pos);

// T
char		*ft_token_status(enum e_status status);
char		*ft_token_type(enum e_token type);
char 		*ft_token_status(enum e_status status);
char 		*ft_token_type(enum e_token type);
char		*ft_token_type_else(enum e_token type);

// U
void		ft_update_list(t_lst *list, char *name, char *new_info);
void 		ft_unset(t_ms *ms);

// V
int			ft_valid_env(char c);

// W
void 		ft_wait(t_ms *ms);
void	ft_cd_while_is_not_pwd(t_ms *ms, t_command *cmd, t_cd *cd);

#endif
