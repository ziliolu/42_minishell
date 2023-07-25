/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_node_list_while.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:27:55 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/25 12:24:03 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

bool	ft_remove_node_list_while(t_lst **head, char *name, \
	t_lst *list, t_lst *tmp)
{
	if (list->next == NULL && ft_strcmp(list->name, name) == 0)
	{
		free(list);
		*head = NULL;
	}
	else if (list->next->next == NULL && ft_strcmp(list->name, name) == 0)
	{
		tmp = list;
		*head = tmp->next;
		free(tmp);
	}
	while (head && list->next)
	{
		if (ft_strcmp(list->next->name, name) == 0)
		{
			tmp = list->next;
			list->next = tmp->next;
			ft_free_node(tmp);
			ft_free(name);
			return (true);
		}
		list = list->next;
	}
	return (false);
}
