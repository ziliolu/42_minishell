/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_args_is_dquote.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:46:42 by ialves-m          #+#    #+#             */
/*   Updated: 2023/07/21 22:50:55 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_elem	*ft_count_args_is_dquote(t_ms *ms, t_elem *list)
{
	list = list->next;
	if (list->status == IN_DQUOTE)
		ms->j++;
	while (list->type != DOUBLE_QUOTE)
		list = list->next;
	list = list->next;
	return (list);
}
