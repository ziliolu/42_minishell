/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:46:42 by ialves-m          #+#    #+#             */
/*   Updated: 2023/06/28 15:47:45 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_count_args(t_ms *ms, t_elem *list)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	ms->n_pipes = ft_count_pipes(list);
	ms->count_args = ft_calloc(sizeof(int), (ms->n_pipes * 2 + 1));
	while (list)
	{
		if (list->type == SINGLE_QUOTE)
		{
			list = list->next;
			if (list->status == IN_SQUOTE)
				j++;
			while (list->type != SINGLE_QUOTE)
				list = list->next;
			list = list->next;
		}
		else if (list->type == DOUBLE_QUOTE)
		{
			list = list->next;
			if (list->status == IN_DQUOTE)
				j++;
			while (list->type != DOUBLE_QUOTE)
				list = list->next;
			list = list->next;
		}
		else if (list->type == WORD)
		{
			j++;
			list = list->next;
		}
		else if (list->type == PIPE_LINE)
		{
			ms->count_args[i++] = j;
			j = 1;
			list = list->next;
			ms->count_args[i++] = j;
			j= 0;
		}
		else if (ft_is_redir(list->type))
		{
			while (list && list->type != PIPE_LINE)
				list = list->next;
		}
		else
			list = list->next;
	}
	ms->count_args[i] = j;
}
