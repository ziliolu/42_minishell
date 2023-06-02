/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:36:32 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/06/02 14:28:16 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

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
		printf("%s\n", read_content);
		add_history(read_content);

		//commands = ft_split(read_content, ' ');
		//ft_run_command(commands[0], env);
	}
}
