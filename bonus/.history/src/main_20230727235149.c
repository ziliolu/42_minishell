/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:36:32 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/27 23:51:49 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	g_exit_status;

int	main(int argc, char **argv, char **system_env)
{
	char	*tmp_prompt;
	char	*prompt;
	char	*read_content;
	t_ms	ms;

	(void) argc;
	(void) argv;
	ms.is_print = 0;
	ms.print_cmd = 0;
	ms.status = 0;
	prompt = "\e[93m minishell _  \e[93m$\033[0m ";
	ms.pid = 0;
	tmp_prompt = NULL;
	read_content = NULL;
	ms.std_in = dup(STDIN_FILENO);
	ms.std_out = dup(STDOUT_FILENO);
	ms.dot_comma_flag = false;
	ft_create_env(&ms, system_env);
	ft_init_ms(&ms, system_env);
	ms.ms_env_array = NULL;
	ms.vars = (t_lst **)ft_calloc(1, sizeof(t_lst *));
	while (1)
		ft_main_cycle(&ms, read_content, tmp_prompt, prompt);
	return (0);
}
