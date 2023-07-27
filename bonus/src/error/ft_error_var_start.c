/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_var_start.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 00:10:00 by ialves-m          #+#    #+#             */
/*   Updated: 2023/07/24 10:43:05 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool	ft_error_var_start(char *msg, char *str, int err_number)
{
	if (str)
	{
		ft_printf("minishell: %s: %s\n", str, msg);
		g_exit_status = err_number;
	}
	return (false);
}
