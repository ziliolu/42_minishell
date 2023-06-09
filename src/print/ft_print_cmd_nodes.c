/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_cmd_nodes.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:49:32 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/06/21 14:28:21 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void ft_print_command_nodes(t_ms *ms, int n_pipes)
{
	int i;
	int j;
	int k;
	i = 0;
	j = 0;
	k = 0;
	printf("\n------ PRINTANDO COMANDOS----------\n");
	while(i < (n_pipes * 2 + 1))
	{
		j = 0;
		printf("\nCOMMAND %i\n", i);
		while(ms->cmds[i].args[j] != NULL)
		{
			printf("%s\n", ms->cmds[i].args[j]); 
			j++;
		}
		if(ms->cmds[i].redirs != NULL)
		{
			while(ms->cmds[i].redirs[k].type)
			{
				printf("%s - %s\n", ft_token_type(ms->cmds[i].redirs[k].type), ms->cmds[i].redirs[k].arg);
				k++;
			}
		}
		k = 0;
		i++;
	}
	printf("--------------------------------------\n\n");
}