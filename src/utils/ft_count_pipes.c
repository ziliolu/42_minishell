/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_pipes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 17:56:37 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/01 23:02:21 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_count_pipes(t_elem *list)
{
	int	pipes;

	pipes = 0;
	while(list != NULL)
	{
		if(list->type == PIPE_LINE)
			pipes++;
		list = list->next;
	}
	return (pipes);
}
