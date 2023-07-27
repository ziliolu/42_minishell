/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_args_is_pipe.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:46:42 by ialves-m          #+#    #+#             */
/*   Updated: 2023/07/21 22:50:37 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_elem	*ft_count_args_is_pipe(t_ms *ms, t_elem *list)
{
	ms->count_args[ms->i++] = ms->j;
	ms->j = 1;
	list = list->next;
	ms->count_args[ms->i++] = ms->j;
	ms->j = 0;
	return (list);
}
