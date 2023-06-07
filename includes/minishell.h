/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:36:28 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/06/07 15:25:05 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H

# include <readline/readline.h>
# include <readline/history.h>
#include <sys/types.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>
# include <sys/wait.h>
# include "../lib/libft/libft.h"


typedef struct s_env
{
    char *name;
	char *info;
    char *full_info;
    struct s_env *next;
}               t_env;

extern t_env **ms_env;

enum e_token
{
	WORD = -1,
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
	DREDIR_OUT,
};

enum e_status
{
	IN_DQUOTE,
	IN_SQUOTE,
	GENERAL,
};

typedef struct s_elem
{
    char *data;
    int len;
    enum e_token type;
    enum e_status status;
    struct s_elem *next;
}               t_elem;

typedef struct s_ms
{
    //char *input;
    char **paths;
    char **system_env;
    char **ms_argv;
}           t_ms;

// ==== utils ====
int 	ft_strcmp(char *s1, char *s2);
void 	ft_run_command(char *command, char **env);
void ft_env(char **env);
char *ft_strndup(char *str, int n);


//-----> ft_env functions <-----//
t_env	*ft_new_node(char *str);
t_env	*ft_find_last(t_env *list);
void	ft_add_node(t_env **header, char *str);
char	*ft_get_env_name(char *set);
char	*ft_get_env_info(char *set);
void	ft_print_list(t_env *list);

void    ft_init_ms(t_ms *ms, char **system_env, char *read_content);
bool ft_is_executable(t_ms *ms);
char    *ft_getenv(char *name);
bool ft_is_absolute_path(char *input);

//-----> ft_is_arg_valid functions <-----//
bool        ft_is_arg_valid(t_ms *ms, char *read_content);
bool        ft_is_quote_valid(char *read_content);
char        ft_choose_quotes(int s_quote, int d_quote);
bool        ft_is_normal_character(char c);

char        *ft_search_for_end(char *str, char c, int pos); 
bool ft_is_variable(t_ms *ms);
bool ft_is_valid_info(t_ms *ms, int j);
char *ft_charjoin(char *str, char c);

t_elem	*ft_new_elem(char *str, int len, enum e_token type, enum e_status);
void	ft_add_new_elem(t_elem **head, t_elem *new_elem);
t_elem	*ft_find_last_elem(t_elem *list);
void ft_lexer(t_ms *ms, char *read_content);
int	ft_size_list(t_elem **header);
void	ft_print_tokens(t_elem *list);
int ft_count_char(char *str);
#endif
