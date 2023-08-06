/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_pipes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 10:01:08 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/08/06 04:45:13 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_init_pipes(t_ms *ms)
{
	int	i;

	i = 0;
	i
	ms->std_in_arr = ft_calloc(ms->n_pipes * 2 + 1, sizeof(int));
	ms->std_out_arr = ft_calloc(ms->n_pipes * 2 + 1, sizeof(int));
	while (ms->cmds[i].type)
	{
		if (ms->cmds[i].type == PIPE_LINE)
			pipe(ms->cmds[i].fd);
		ms->std_in_arr[i] = dup(STDIN_FILENO);
		ms->std_out_arr[i] = dup(STDOUT_FILENO);
		i++;
	}
}
