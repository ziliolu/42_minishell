/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_is_cmd_arg.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 13:05:23 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/08/05 16:34:38 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char	*ft_exit_is_cmd_arg(t_ms *ms, t_command *cmd, char *tmp)
{
	(void) ms;
	if (cmd->args[1])
	{
		tmp = ft_strdup(cmd->args[1]);
		ms->atoi_tmp = ft_atoi(tmp);
	}
	return (tmp);
}
