/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 23:48:48 by ialves-m          #+#    #+#             */
/*   Updated: 2023/07/21 11:55:29 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char	*ft_getenv(t_ms *ms, char *name)
{
	t_lst	*list;

	list = ms->ms_env;
	while (list)
	{
		if (ft_strcmp(list->name, name) == 0)
			return (list->info);
		list = list->next;
	}
	return (NULL);
}
