/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 21:10:52 by ialves-m          #+#    #+#             */
/*   Updated: 2023/07/24 21:10:54 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

t_lst	*ft_new_node(char *str)
{
	t_lst	*var;

	var = (t_lst *)ft_calloc(1, sizeof(t_lst));
	if (var)
	{
		var->name = ft_get_list_name(str);
		var->info = ft_get_list_info(str);
		var->full_info = ft_strdup(str);
		var->next = NULL;
		return (var);
	}
	free (var);
	return (NULL);
}
