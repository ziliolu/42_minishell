/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:36:32 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/26 20:59:19 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	g_exit_status;

int	main(int argc, char **argv, char **system_env)
{
	char	*prompt;
	char	*tmp_prompt;
	char	*read_content;
	t_ms	ms;

	(void) argc;
	(void) argv;
	prompt = "minishell> ";
	ms.is_print = 1;
	ms.print_cmd = 0;
	ms.status = 0;
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
