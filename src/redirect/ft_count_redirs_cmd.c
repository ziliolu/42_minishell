/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_redirs_cmd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 18:14:39 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/22 21:18:27 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_count_redirs_cmd(t_command *cmd)
{
	int	i;

	i = 0;
	while (cmd->redirs[i].arg != NULL)
	{
		i++;
	}
	return (i);
}
