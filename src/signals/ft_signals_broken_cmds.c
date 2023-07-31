/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signals_broken_cmds.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 00:55:09 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/31 09:04:43 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_handler_broken_cmds(int signal)
{
	if (signal == SIGINT)
	{
		//rl_replace_line("", 0);
		//printf("\n");
		//rl_on_new_line();
		//rl_redisplay();
		//printf(" ola");
		g_exit_status = 130;
		//exit(g_exit_status);
	}
}
void	ft_signals_broken_cmds(void)
{
	signal(SIGINT, ft_handler_broken_cmds);
}
