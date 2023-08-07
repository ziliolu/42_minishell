/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signals_ignore.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 12:05:11 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/08/07 04:39:24 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_handler_ignore(int signal)
{
	if (signal == SIGINT)
		g_exit_status = 130;
}

void	ft_signals_ignore(void)
{
	signal(SIGINT, ft_handler_ignore);
	signal(SIGQUIT, SIG_IGN);
}
