/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_redirs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 18:14:39 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/22 21:16:34 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_count_redirs(t_elem *list)
{
	int	i;

	i = 0;
	while (list && list->type != PIPE_LINE)
	{
		if (!ft_is_not_redir(list->type))
			i++;
		list = list->next;
	}
	return (i);
}
