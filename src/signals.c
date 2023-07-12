/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 16:27:26 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/12 21:01:15 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include <unistd.h>
void ft_handler(int signal)
{
	if(signal == SIGINT)
	{
		// if (getpid() == 0)
		// 	printf("PID %d\n", getpid());
		// else
		// 	printf("PID %d\n", getpid());

		rl_replace_line("", 0);
		printf("\n");
		rl_on_new_line();
		rl_redisplay();
		g_exit_status = 130;
	}
	if(signal == SIGQUIT)
	{
		rl_replace_line("", 0);
		printf("Quit (core dumped)\n");
		rl_on_new_line();
		rl_redisplay();
		g_exit_status = 130;
	}
}
void ft_handle_signals()
{
	signal(SIGINT, ft_handler);
	signal(SIGQUIT, ft_handler);
}
