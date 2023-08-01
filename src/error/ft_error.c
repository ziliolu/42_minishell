/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 10:33:52 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/24 12:04:02 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool	ft_error(t_ms *ms, char *msg, char *str, int err_n)
{
	ft_reset_fd_in_out(ms);
	if (!str)
		ft_printf("minishell: %s\n", msg);
	else
		ft_printf("minishell: %s: %s\n", msg, str);
	g_exit_status = err_n;
	return (false);
}
