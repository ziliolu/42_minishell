/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 16:27:26 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/13 10:15:33 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include <unistd.h>
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

void ft_handler_loop(int signal)
{
	if(signal == SIGINT)
	{
		printf("\n");
		//g_exit_status = 130;
		printf("STATUS %d\n", g_exit_status);

	}
	if(signal == SIGQUIT)
	{
		printf("Quit (core dumped)\n");
		//g_exit_status = 131;
	}
}

void ft_handle_signals()
{
	signal(SIGINT, ft_handler);
	signal(SIGQUIT, SIG_IGN);
}

void ft_handle_signals_loop()
{
	signal(SIGINT, ft_handler_loop);
	signal(SIGQUIT, ft_handler_loop);
}
 