/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:36:28 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/08/12 07:39:50 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

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
# include <limits.h>
# include <signal.h>

# define HEREDOC "heredoc.tmp"

# define HEREDOC "heredoc.tmp"
# define RED "\001\e[0;31m\002"
# define ORG "\001\e[93m\002"
# define GRN "\001\e[32m\002"
# define LGRN "\001\e[92m\002"
# define BLU "\001\e[34m\002"
# define LBLU "\001\e[94m\002"
# define RESET "\001\e[0m\002"

extern int	g_exit_status;

typedef struct s_lst
{
	char			*name;
	char			*info;
	char			*full_info;
	struct s_lst	*next;
}	t_lst;

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

enum e_status
{
	IN_DQUOTE,
	IN_SQUOTE,
	GENERAL,
};

typedef struct s_elem
{
	enum e_token	type;
	enum e_status	status;
	char			*data;
	int				len;
	struct s_elem	*next;
}	t_elem;

typedef struct s_pipe
{
	struct s_elem	*right_command;
	struct s_elem	*left_command;
}	t_pipe;

typedef struct s_redirect
{
	enum e_token	type;
	char			*arg;
}	t_redirect;

typedef struct s_command
{
	t_redirect		*redirs;
	enum e_token	operator;
	enum e_token	type;
	char			**args;
	int				in;
	int				out;
	int				fd[2];
	int				pid;
	int				status;
	bool			err;
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
	t_lst		*export_list;
	t_elem		**lexed_list;
	t_lst		**vars;
	t_command	*cmds;
	t_pipe		*pipes;
	char		**ms_env_array;
	char		**paths;
	char		**system_env;
	char		**ms_argv;
	int			*count_args;
	int			read_size;
	int			n_pipes;
	int			std_in;
	int			std_out;
	int			is_print;
	int			print_cmd;
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
	char		*home_dir;
	char		*clean_read_content;
	t_counters	*clean;
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
	char	upper_case;
	char	lower_case;
	char	underscore;
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
	t_ms	*ms;
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

typedef struct s_trim
{
	char	*tmp;
	char	*str_tmp;
	int		i;
	int		j;
}	t_trim;

typedef struct s_env_to_array
{
	int		size;
	int		i;
	int		tmp_size;
	char	**array;
	t_lst	*lst;
}	t_env_to_array;

typedef struct s_val_redir
{
	enum e_token	type;
	int				i;
	int				j;
	char			*arg;
}	t_val_redir;

typedef struct s_val_quote
{
	int	i;
	int	s_quote;
	int	d_quote;
}	t_val_quote;

// =============== BUILTINS ===============

void	ft_cd_is_chdir(t_ms *ms, t_command *cmd, t_cd *cd);
void	ft_is_not_pwd(t_ms *ms, t_command *cmd, t_cd *cd);
void	ft_cd_while_is_not_pwd(t_ms *ms, t_command *cmd, t_cd *cd);
void	ft_cd(t_ms *ms, t_command *cmd);
void	ft_create_env(t_ms *ms, char **env);
void	ft_create_exp(t_ms *ms, char **env);
void	ft_echo_is_cmd_arg(t_command *cmd, t_echo *echo);
void	ft_echo(t_command *cmd);
bool	echo_is_n(char *arg);
void	ft_env(t_ms *ms, t_command *cmd, t_lst *lst);
bool	ft_find_in_array(char *str, char **array);
void	ft_exit_free(t_ms *ms);
char	*ft_exit_is_cmd_arg(t_ms *ms, t_command *cmd, char *tmp);
bool	ft_exit_validation(t_ms *ms, t_command *cmd);
void	ft_exit(t_ms *ms, t_command *cmd);
void	ft_exit_local_free(t_ms *ms);
void	ft_export_is_cmd_arg(t_ms *ms, t_command *cmd, int i);
void	ft_export_is_in_env_list(t_ms *ms, t_command *cmd, t_export *exp);
void	ft_export_is_in_env_list_else(t_ms *ms, t_command *cmd, t_export *exp);
void	ft_creat_exp_free(t_export *exp, t_lst **env_head);
void	ft_export(t_ms *ms, t_command *cmd);
void	ft_unset(t_ms *ms, t_command *cmd);
void	ft_join_old_w_new_pwd(t_cd *cd);
void	ft_is_not_export_cmd(t_ms *ms, t_command *cmd);
void	ft_exit_is_not_pipe(t_ms *ms, char *tmp, int pipes);

// =============== ERROR ===============

bool	ft_error_var_start(char *msg, char *str, int err_number);
bool	ft_error(t_ms *ms, char *msg, char *str, int err_n);
bool	ft_error_wo_prompt(t_ms *ms, char *msg, char *str, int err_n);

// =============== EXECUTABLE ===============

bool	ft_is_absolute_path(char *str);
void	ft_is_executable_while_path(t_ms *ms, t_command *cmd, \
	char **path_w_slash, char **total_path);
bool	ft_is_executable(t_ms *ms, t_command *cmd);
bool	ft_is_home_path(char *str);
void	ft_start_fork(t_ms *ms, t_command *cmd, char **total_path);

// =============== LEXER ===============

void	ft_add_new_elem(t_elem **head, t_elem *new_elem);
t_elem	*ft_count_args_is_dquote(t_ms *ms, t_elem *list);
t_elem	*ft_count_args_is_pipe(t_ms *ms, t_elem *list);
t_elem	*ft_count_args_is_squote(t_ms *ms, t_elem *list);
t_elem	*ft_count_args_is_word(t_ms *ms, t_elem *list);
void	ft_count_args(t_ms *ms, t_elem *list);
int		ft_count_char_env(char *str);
int		ft_count_char(char *str);
t_elem	*ft_find_last_elem(t_elem *list);
void	ft_lexer_if_str_dquote(t_lexer *x, t_elem **elem_head, \
	char *str, enum e_status *status);
void	ft_lexer_if_str_else(t_lexer *x, t_elem **elem_head, \
	char *str, enum e_status *status);
void	ft_lexer_if_str_redir_in(t_lexer *x, t_elem **elem_head, \
	char *str, enum e_status *status);
void	ft_lexer_if_str_redir_out(t_lexer *x, t_elem **elem_head, \
	char *str, enum e_status *status);
void	ft_lexer_if_str_squote(t_lexer *x, t_elem **elem_head, \
	char *str, enum e_status *status);
void	ft_lexer_if_while_str(t_lexer *x, t_elem **elem_head, \
	char *str, enum e_status *status);
void	ft_lexer_is_squote(t_lexer *x, enum e_status *status, \
	t_elem **elem_head, char *str);
void	ft_lexer(t_ms *ms, char *str);
t_elem	*ft_new_elem(char *str, int len, enum e_token type, \
	enum e_status *status);
int		ft_size_list(t_elem **header);
char	*ft_token_status(enum e_status status);
char	*ft_token_type_else(enum e_token type);
char	*ft_token_type(enum e_token type);
int		ft_valid_env(char c);

// =============== PARSER ===============

int		ft_count_tokens(t_elem *list);
char	*ft_expand_while_env(t_lst *env, t_lst *vars, char *str);
char	*ft_expand_while_vars(t_lst *env, t_lst *vars, char *str);
char	*ft_expand(t_lst *env, t_lst *vars, char *variable);
void	ft_is_env_and_squote(t_ms *ms, t_counters *p);
void	ft_is_env_in_quotes(t_counters *p, char *tmp_exp_or_data);
void	ft_is_in_double_quote_while(t_ms *ms, t_counters *p, char *data);
void	ft_is_in_double_quote(t_ms *ms, t_counters *p);
void	ft_is_in_single_quote(t_ms *ms, t_counters *p);
void	ft_is_redir_double_quote(t_ms *ms, t_counters *p);
void	ft_is_redir_single_quote(t_ms *ms, t_counters *p);
void	ft_is_redir_type(t_ms *ms, t_counters *p);
void	ft_parser_count_pipes(t_ms *ms, t_counters *p);
void	ft_parser_is_not_null(t_ms *ms, t_counters *p, \
	char *tmp_arg, char *tmp_list);
void	ft_parser_is(t_ms *ms, t_counters *p);
void	ft_parser_while_dif_null(t_ms *ms, t_counters *p, int c);
void	ft_parser_while_dif_pipe(t_ms *ms, t_counters *p, int c);
void	ft_parser(t_ms *ms, t_elem *list);
void	ft_ptr_is_in_quotes(t_ms *ms, t_counters *p);
void	ft_list_type_env(t_ms *ms, t_counters *p);

// =============== PIPES ===============

char	*ft_broken_cmds(t_ms *ms, char *str);
int		ft_count_pipes(t_elem *list);
bool	ft_input_is_pipe(t_ms *ms, char **tmp, char *str, t_broken_cmds *b);
char	*ft_is_broken_cmds_pipe(t_ms *ms, char *str, t_broken_cmds *b);
void	ft_close_pipes(t_ms *ms);
void	ft_init_pipes(t_ms *ms);

// =============== PRINT ===============

void	ft_print_array(char **str);
void	ft_print_command_nodes_while_pipe(t_ms *ms, int i, int j, int k);
void	ft_print_command_nodes(t_ms *ms, int n_pipes);
void	ft_print_export(t_lst *lst);
void	ft_print_list(t_lst *lst);
void	ft_print_local_variables(t_lst **head);
void	ft_print_tokens(t_ms *ms, t_elem *list);

// =============== REDIRECT ===============

bool	ft_is_ctrld_heredoc(t_command *cmd, t_heredoc *h);
int		ft_count_redirs_cmd(t_command *cmd);
int		ft_count_redirs(t_elem *list);
bool	ft_is_arg_redir(char *arg);
bool	ft_is_not_redir(enum e_token type);
bool	ft_is_redir(enum e_token type);
void	ft_is_heredoc_read_content(t_ms *ms, t_command *cmd, t_heredoc *h);
bool	ft_is_heredoc(t_ms *ms, t_command *cmd, t_redirect *redir, int i);
bool	ft_open_redirs_if_others(t_ms *ms, t_counters *c);
bool	ft_open_redirs(t_ms *ms, t_counters *c);
bool	ft_open_redirs_if_var(t_ms *ms, t_counters *c, char *tmp_arg);
char	*ft_expand_heredoc(t_lst *env, t_lst *vars, char *variable);
void	ft_join_heredoc_inputs(t_ms *ms, t_heredoc *h, char **tmp);

// =============== RUN ===============

bool	ft_change_standard_in_out(t_command *cmd);
void	ft_connect_pipes(t_ms *ms, t_counters *c);
int		ft_count_cmds(t_ms *ms);
void	ft_filter_cmd_else(t_ms *ms, t_command *cmd);
void	ft_filter_cmd(t_ms *ms, t_command *cmd);
void	ft_main_cycle(t_ms *ms, char *read_content, \
	char *tmp_prompt, char *prompt);
char	*ft_trimmed(char *str);
bool	ft_main_cycle_read(t_ms *ms, char **read_content, char *prompt);
void	ft_reset_fd_in_out(t_ms *ms);
void	ft_reset_heredoc(t_ms *ms, int i);
void	ft_run_cmds(t_ms *ms);
void	ft_wait(t_ms *ms);
void	ft_init_ms(t_ms *ms, char **system_env);

// =============== SIGNALS ===============

void	ft_handle_signals_loop(void);
void	ft_handle_signals(void);
void	ft_handler_loop(int signal);
void	ft_handler(int signal);
void	ft_signals_heredoc(void);
void	ft_signals_ignore(void);

// =============== UTILS ===============

// ------------ 1- FREE MEMORY ------------

void	ft_free_array(char **array);
void	ft_free_cmds_while(t_ms *ms, int i, int j, int k);
void	ft_free_cmds(t_ms *ms);
void	ft_free_counters(t_counters *c);
void	ft_free_elem_list(t_elem *head);
void	ft_free_env(t_lst *ms_lst);
void	ft_free_memory(t_ms *ms);
void	ft_free_node(t_lst *node);
void	ft_free(char *str);

// ------------ 2- GENERAL ------------

char	*ft_charjoin(char *str, char c);
void	ft_chartrim_w_dquotes_while(t_trim *t, char *str, char c);
char	*ft_chartrim_w_dquotes(char *str, char c);
void	ft_chartrim_wo_dquotes_while(t_trim *t, char *str, char c);
char	*ft_chartrim_wo_dquotes(char *str, char c);
char	ft_choose_quotes(int s_quote, int d_quote);
bool	ft_env_to_array_while(t_ms *ms, t_env_to_array *e);
char	**ft_list_to_array(t_ms *ms);
char	*ft_format_slash(char *str);
bool	ft_is_dot_comma(char *str);
bool	ft_is_export_type(char *str);
void	ft_is_not_read_content(t_ms *ms, char *read_content);
bool	ft_is_there_quote(char *str);
bool	ft_is_there_space(char *str);
char	*ft_search_for_end(char *str, char c, int pos);
char	*ft_strchr_vars(char *s, char c);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strjoin_wo_leaks(char *s1, char *s2);
char	*ft_strndup(char *str, int n);
char	*ft_strtrim_end_quote(char *str, char set);
char	*ft_strtrim_end(char *str, char set);
bool	ft_is_in_llong_range(char *nptr);
char	*ft_getcwd(void);

// ------------ 3- LIST UTILS ------------

void	ft_add_export_node(t_lst **header, char *str);
void	ft_add_node_to_list(t_ms *ms, t_lst **head, char *str);
void	ft_add_node(t_lst **header, char *str);
t_lst	*ft_find_last(t_lst *head);
t_lst	*ft_find_second_to_last(t_lst **head);
char	*ft_get_list_info(char *set);
char	*ft_get_list_name(char *set);
char	*ft_getenv(t_ms *ms, char *name);
bool	ft_is_already_in_list(char *name, t_lst *list);
t_lst	*ft_new_node(char *str);
bool	ft_remove_node_list_while(t_lst **head, char *name, \
	t_lst *list, t_lst *tmp);
void	ft_remove_node_list(t_lst **head, char *str, t_command *cmd);
char	*ft_return_list_full_info(t_lst *lst, char *name);
char	*ft_return_list_info(t_lst *lst, char *name);
void	ft_update_list(t_lst *list, char *name, char *new_info);

// ------------ 4- VALIDATIONS ------------

bool	ft_arg_exist(char *arg);
bool	ft_cmd_args_validation(t_ms *ms);
void	ft_if_readline_is_valid(t_ms *ms, char *read_content);
void	ft_if_valid_info_is_dquote(t_ms *ms, int j, char *str, char *var_info);
void	ft_if_valid_info_is_squote(t_ms *ms, int j, char *str, char *var_info);
bool	ft_is_arg_valid(t_ms *ms, char *read_content);
bool	ft_is_quote_valid_msg(char *read_content, int s_quote, int d_quote);
bool	ft_is_quote_valid(char *read_content);
bool	ft_is_valid_character(char character);
bool	ft_is_valid_info(t_ms *ms, int j);
bool	ft_is_variable(t_ms *ms);
bool	ft_pipe_validation(t_ms *ms);
bool	ft_redirs_validation_while(t_ms *ms, t_val_redir *r);
bool	ft_redirs_validation(t_ms *ms);
bool	ft_is_valid_number(char c);
bool	ft_is_valid_env_name(t_ms *ms, char *str);
bool	ft_is_not_valid_identifier(t_ms *ms, t_command *cmd, int i, int *err);

#endif
