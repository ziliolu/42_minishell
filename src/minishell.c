/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:36:32 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/06/02 17:56:56 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"



int main(int argc, char **argv, char **env)
{
	 
	char *prompt;
	char *read_content;
	t_env *lista;
	//char **commands;

	(void)argc;
	(void)argv;
	ft_env(env); 
	prompt = "minishell> ";
	while (1)
	{
		read_content = readline(prompt);
		add_history(read_content);
		// if(read_content == "ls")
		// {
		// 	ft_search_env();
		// }
		
		//commands = ft_split(read_content, ' ');
		//ft_run_command(commands[0], env);
	}
}

// char *ft_search_env(char *str)
// {
// 	while(env)
// 	{
// 		if(env->name == str)
// 			return(env->info);
// 		env = env->next;
// 	}
// 	return(NULL);
// }
