/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:36:28 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/06/05 18:09:13 by lpicoli-         ###   ########.fr       */
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
#endif
