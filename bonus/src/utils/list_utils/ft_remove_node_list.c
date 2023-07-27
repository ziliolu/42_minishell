/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_node_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:27:55 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/27 12:22:44 by ialves-m         ###   ########.fr       */
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
	if (ft_strcmp(cmd->args[0], "unset") != 0)
		name = ft_get_list_name(str);
	else
		name = ft_strdup(str);
	if (ft_remove_node_list_while(head, name, list, tmp))
	{
		ft_free(name);
		return ;
	}
	ft_free(name);
}
