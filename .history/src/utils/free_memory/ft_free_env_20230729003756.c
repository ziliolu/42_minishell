/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:36:32 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/29 00:37:56 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	ft_free_env(t_lst *ms_lst)
{
	t_lst	*list;

	list = NULL;
	list = ms_lst;
	while (ms_lst)
	{
		if (ms_lst)
		{
			list = ms_lst->next;
			free (ms_lst->name);
			free (ms_lst->info);
			free (ms_lst->full_info);
			free (ms_lst);
		}
		ms_lst = list;
	}
	if (list)
		free (list);
}
