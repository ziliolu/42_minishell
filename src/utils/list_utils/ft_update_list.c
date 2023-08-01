/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_lst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 11:45:26 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/04 15:31:02 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	ft_update_list(t_lst *list, char *name, char *new_info)
{
	char	*tmp_full_info;

	while (list)
	{
		if (ft_strcmp(list->name, name) == 0)
		{
			ft_free(list->info);
			ft_free(list->full_info);
			tmp_full_info = ft_strjoin("=", new_info);
			list->full_info = ft_strjoin(name, tmp_full_info);
			list->info = ft_strdup(new_info);
			free(tmp_full_info);
			return ;
		}
		list = list->next;
	}
}
