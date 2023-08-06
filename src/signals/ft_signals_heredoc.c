/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signals_heredoc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 00:55:09 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/08/06 15:39:18 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_handler_heredoc(int signal)
{
	if (signal == SIGINT)
	{
		printf("\n");
		g_exit_status = 130;
		exit(g_exit_status);
	}
}

void	ft_signals_heredoc(void)
{
	signal(SIGINT, ft_handler_heredoc);
	signal(SIGQUIT, SIG_IGN);
}
