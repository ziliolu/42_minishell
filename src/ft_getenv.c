/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 23:48:48 by ialves-m          #+#    #+#             */
/*   Updated: 2023/07/20 23:53:44 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

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
