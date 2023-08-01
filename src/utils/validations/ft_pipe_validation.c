/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe_validation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 10:28:08 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/24 23:05:51 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

bool	ft_pipe_validation(t_ms *ms)
{
	t_elem	*list;

	list = *ms->lexed_list;
	while (list)
	{
		if (list->type == PIPE_LINE)
		{
			while (list->next->type == WHITE_SPACE)
				list = list->next;
			if (list->next->type == PIPE_LINE)
				return (\
				ft_error(ms, "syntax error near unexpected token `|'", \
				NULL, 2));
		}
		list = list->next;
	}
	return (true);
}
