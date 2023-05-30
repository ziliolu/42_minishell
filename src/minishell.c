/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:36:32 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/05/30 11:03:56 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int main(int argc, char **argv, char **env)
{
	char *prompt;
	char *read_content;
	char **commands;
	int i;
	t_info info;

	(void)argc;
	(void)argv;
	i = 0;
	prompt = "minishell> ";
	info.env = ft_create_env(env);
	while(info.env != NULL)
	{
		ft_getenv(info.env);
		info.env++;
	}
	while (1)
	{
		read_content = readline(prompt);
		printf("%s\n", read_content);
		add_history(read_content);

		commands = ft_split(read_content, ' ');
		ft_run_command(commands[0], env);
	}
}
        
void ft_run_command(char *command, char **env)
{
    if(ft_strcmp("env", command) == 0)
        ft_env(env);
}

t_env *ft_create_env(char **env)
{
	int i;
	t_env *new_env;

	i = 0;
	new_env = malloc(sizeof(t_env *));
	while(env[i])
	{
		ft_addback_lst(&new_env, ft_newnode("nooome", "ola"));
		i++;
	}
	return (new_env);
}

void ft_getenv(t_env *node)
{
	if (node)
	{
		printf("FRUTA: %s\n", node->name);
		node = node->next;
	}
}

t_env	*ft_newnode(char *name, char *total_info)
{
	t_env	*node;

	node = malloc(sizeof(*node));
	if (!node)
		return (NULL);
	node->name = name;
	node->total_info = total_info;
    node->next = NULL;
	return (node);
}

void	ft_addback_lst(t_env **lst, t_env *new)
{
	t_env	*last;

	last = *lst;
	if (!lst || ! new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	while (last->next)
		last = last->next;
	last->next = new;
}