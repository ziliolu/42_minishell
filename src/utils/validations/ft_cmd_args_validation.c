/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_args_validation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 00:08:14 by ialves-m          #+#    #+#             */
/*   Updated: 2023/07/26 21:04:50 by ialves-m         ###   ########.fr       */
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
