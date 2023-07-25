/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_close_file_descriptors.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 11:07:56 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/22 17:59:00 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_close_pipes(t_ms *ms)
{
	int	i;

	i = 0;
	while (ms->cmds[i].args)
	{
		if (ms->cmds[i].type == PIPE_LINE)
		{
			close(ms->cmds[i].fd[0]);
			close(ms->cmds[i].fd[1]);
		}
		i++;
	}
}
