/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_args_validation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 00:08:14 by ialves-m          #+#    #+#             */
/*   Updated: 2023/07/21 11:57:01 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

bool	ft_cmd_args_validation(t_ms *ms)
{
	if (!ft_redirs_validation(ms))
		return (false);
	if (!ft_pipe_validation(ms))
		return (false);
	return (true);
}
