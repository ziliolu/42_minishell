/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 16:27:26 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/06/26 11:46:55 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
void ft_handler(int signal)
{
	if(signal == SIGINT)
	{
		rl_replace_line("", 0);
		printf("\n");
		rl_on_new_line();
		rl_redisplay();
		g_exit_status = 130;
	}
}
void ft_handle_signals()
{
	signal(SIGINT, ft_handler);
	signal(SIGQUIT, SIG_IGN);
}
