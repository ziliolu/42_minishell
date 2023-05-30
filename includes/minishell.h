/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:36:28 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/05/30 11:03:14 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H

#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include <stdio.h>
#include "../lib/libft/libft.h"

typedef struct s_env
{
    char *name;
    char *total_info;
    struct s_env *next;
    struct s_env *prev;
}               t_env;

typedef struct s_info
{
    t_env *env;
    
}               t_info;

void ft_env(char **env);
void ft_getenv(t_env *env);
// ==== utils ====
int ft_strcmp(char *s1, char *s2);
t_env	*ft_newnode(char *name, char *total_info);
void	ft_addback_lst(t_env **lst, t_env *new);
t_env *ft_create_env(char **env);
void ft_run_command(char *command, char **env);

#endif