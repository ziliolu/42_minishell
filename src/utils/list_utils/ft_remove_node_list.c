/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_node_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:27:55 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/25 11:21:36 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	ft_remove_node_list(t_lst **head, char *str, t_command *cmd)
{
	t_lst	*tmp;
	t_lst	*list;
	char	*name;

	tmp = NULL;
	list = *head;
	if (!str)
		return ;
	if(ft_strcmp(cmd->args[0], "unset") != 0)
		name = ft_get_list_name(str);
	else
		name = ft_strdup(str);
	ft_remove_node_list_while(head, name, list, tmp);
	while (head && list->next)
	{
		if (ft_strcmp(list->next->name, name) == 0)
		{
			tmp = list->next;
			list->next = tmp->next;
			ft_free_node(tmp);
			ft_free(name);
			return ;
		}
		list = list->next;
	}
	ft_free(name);
}
