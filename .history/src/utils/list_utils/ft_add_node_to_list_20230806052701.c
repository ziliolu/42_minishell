/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_node_to_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:28:23 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/08/06 05:27:01 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	ft_add_node_to_list(t_ms *ms, t_lst **head, char *str)
{
	char	*name;
	char	*tmp;

	name = ft_get_list_name(str);
	if (ft_is_already_in_list(name, *head))
	{
		tmp = ft_get_list_info(str);
		ft_update_list(*head, name, ft_get_list_info(str));
		ft_free (tmp);
		return ;
	}
	else if (ft_is_already_in_list(name, ms->ms_env))
	{
		tmp = ft_get_list_info(str);
		ft_update_list(ms->ms_env, name, tmp);
		ft_free (tmp);
	}
	ft_add_node(head, str);
	ft_free(name);
}
