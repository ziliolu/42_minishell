/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:36:28 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/06/02 17:56:56 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H

# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <stdio.h>
# include "../lib/libft/libft.h"


typedef struct s_env
{
    char *name;
	char *info;
    char *full_info;
    struct s_env *next;
}               t_env;

t_env **g_env;


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

#endif
