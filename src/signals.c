/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 16:27:26 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/06/22 17:22:27 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
​
void ft_handler(int signal)
{
	if(signal == SIGINT)
	{
		printf("\n");
		rl_on_new_line();
		rl_redisplay();
		//g_exit_status = 130;
	}
}
void ft_handle_signals()
{
	signal(SIGINT, ft_handler);
	signal(SIGQUIT, SIG_IGN);
}
