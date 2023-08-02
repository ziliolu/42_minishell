/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_cmd_nodes.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:49:32 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/08/01 15:38:11 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_print_command_nodes(t_ms *ms, int n_pipes)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	printf("\n|-------------> PARSER <---------------|\n");
	while (i < (n_pipes * 2 + 1))
	{
		ft_print_command_nodes_while_pipe(ms, i, j, k);
		k = 0;
		i++;
	}
	printf("|                                       |\n");
	printf("|---------------------------------------|\n");
}
