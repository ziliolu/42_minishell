/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_args_is_squote.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:46:42 by ialves-m          #+#    #+#             */
/*   Updated: 2023/07/21 22:48:49 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_elem	*ft_count_args_is_squote(t_ms *ms, t_elem *list)
{
	list = list->next;
	if (list->status == IN_SQUOTE)
		ms->j++;
	while (list->type != SINGLE_QUOTE)
		list = list->next;
	list = list->next;
	return (list);
}
