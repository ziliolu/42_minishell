/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_node_list_while.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:27:55 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/24 21:50:14 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	ft_remove_node_list_while(t_lst **head, char *name, \
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
}
