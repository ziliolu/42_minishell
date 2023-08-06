/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_pipes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 10:01:08 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/08/06 14:24:44 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_init_pipes(t_ms *ms)
{
	int	i;

	i = 0;
	while (ms->cmds[i].type)
	{
		if (ms->cmds[i].type == PIPE_LINE)
			pipe(ms->cmds[i].fd);
		i++;
	}
}
