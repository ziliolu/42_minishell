/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_loop.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 00:54:14 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/25 12:18:55 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_handler_loop(int signal)
{
	if (signal == SIGINT)
	{
		printf("\n");
		g_exit_status = 130;
	}
	if (signal == SIGQUIT)
	{
		printf("Quit (core dumped)\n");
		g_exit_status = 131;
	}
}
