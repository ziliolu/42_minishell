/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_cmd_nodes_while_pipe.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:49:32 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/26 19:52:27 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_print_command_nodes_while_pipe(t_ms *ms, int i, int j, int k)
{
	j = 0;
	printf("\n|\t\tCOMMAND %i\t\t|\n", i);
	while (ms->cmds[i].args[j] != NULL)
	{
		printf("|\t\t%s\t\t\t|\n", ms->cmds[i].args[j]);
		j++;
	}
	printf("|\t\t\t\t\t|");
	if (ms->cmds[i].redirs != NULL)
	{
		while (ms->cmds[i].redirs[k].type)
		{
			printf("%s - %s\n", ft_token_type(ms->cmds[i].redirs[k].type), \
			ms->cmds[i].redirs[k].arg);
			k++;
		}
	}
}
