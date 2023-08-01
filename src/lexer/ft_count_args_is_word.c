/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_args_is_word.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:46:42 by ialves-m          #+#    #+#             */
/*   Updated: 2023/07/21 22:47:36 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_elem	*ft_count_args_is_word(t_ms *ms, t_elem *list)
{
	ms->j++;
	list = list->next;
	return (list);
}
