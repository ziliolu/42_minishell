/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:36:32 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/08/16 12:48:00 by lpicoli-         ###   ########.fr       */
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
	ms.status = 0;
	prompt = RED"mi"ORG"ni"GRN"s"LGRN"h"BLU"e"LBLU"ll"ORG"$ "RESET;
	ms.pid = 0;
	tmp_prompt = NULL;
	read_content = NULL;
	ms.std_in = dup(STDIN_FILENO);
	ms.std_out = dup(STDOUT_FILENO);
	ms.dot_comma_flag = false;
	ft_create_env(&ms, system_env);
	ft_create_exp(&ms, system_env);
	ft_init_ms(&ms, system_env);
	ms.ms_env_array = NULL;
	ms.vars = (t_lst **)ft_calloc(1, sizeof(t_lst *));
	ms.home_dir = ft_return_list_info(ms.ms_env, "HOME");
	while (1)
		ft_main_cycle(&ms, read_content, tmp_prompt, prompt);
}
