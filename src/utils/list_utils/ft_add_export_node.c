/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_export_node.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 21:15:51 by ialves-m          #+#    #+#             */
/*   Updated: 2023/07/24 21:20:28 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	ft_add_export_node(t_lst **header, char *str)
{
	t_lst	*new;
	t_lst	*tmp;

	new = ft_new_node(str);
	if (*header == NULL)
	{
		*header = new;
		return ;
	}
	tmp = ft_find_last(*header);
	tmp->next = new;
	new->next = NULL;
}
