/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_second_to_last.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 21:15:51 by ialves-m          #+#    #+#             */
/*   Updated: 2023/07/24 21:21:28 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

t_lst	*ft_find_second_to_last(t_lst **head)
{
	t_lst	*list;

	list = *head;
	while (list->next)
	{
		if (ft_strcmp(list->next->name, "LANG") == 0)
			return (list);
		list = list->next;
	}
	return (NULL);
}
