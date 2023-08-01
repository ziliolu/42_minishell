/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:46:42 by ialves-m          #+#    #+#             */
/*   Updated: 2023/07/21 22:49:39 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_count_args(t_ms *ms, t_elem *list)
{
	ms->i = 0;
	ms->j = 0;
	ms->n_pipes = ft_count_pipes(list);
	ms->count_args = ft_calloc(sizeof(int), (ms->n_pipes * 2 + 1));
	while (list)
	{
		if (list->type == SINGLE_QUOTE)
			list = ft_count_args_is_squote(ms, list);
		else if (list->type == DOUBLE_QUOTE)
			list = ft_count_args_is_dquote(ms, list);
		else if (list->type == WORD)
			list = ft_count_args_is_word(ms, list);
		else if (list->type == PIPE_LINE)
			list = ft_count_args_is_pipe(ms, list);
		else if (ft_is_redir(list->type))
		{
			while (list && list->type != PIPE_LINE)
				list = list->next;
		}
		else
			list = list->next;
	}
	ms->count_args[ms->i] = ms->j;
}
