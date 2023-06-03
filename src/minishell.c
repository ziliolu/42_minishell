/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:36:32 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/06/03 18:30:10 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_env **g_env;

int main(int argc, char **argv, char **env)
{
	 
	char *prompt;
	char *read_content;
	//char **commands;

	(void)argc;
	(void)argv;
	ft_env(env); 

	prompt = "minishell> ";
	while (1)
	{
		read_content = readline(prompt);
		add_history(read_content);
		if(!ft_strcmp(read_content, "pwd"))
		{
			printf("%s\n", ft_search_env("PWD"));
		}
		//commands = ft_split(read_content, ' ');
		//ft_run_command(commands[0], env);
	}
}

char *ft_search_env(char *str)
{
	t_env *list;

	list = *g_env;
	while(list)
	{
		if(ft_strcmp(list->name, str) == 0)
			return(list->info);
		list = list->next;
	}
	return(NULL);
}
