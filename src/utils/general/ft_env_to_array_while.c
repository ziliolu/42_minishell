/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_to_array_while.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 16:03:14 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/24 23:09:49 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

bool	ft_env_to_array_while(t_ms *ms, t_env_to_array *e)
{
	(void) ms;
	while (e->i < e->size)
	{
		e->tmp_size = ft_strlen(e->lst->full_info) + 1;
		e->array[e->i] = (char *)ft_calloc(e->tmp_size, sizeof(char));
		if (!e->array[e->i])
			return (false);
		ft_strlcpy(e->array[e->i], e->lst->full_info, e->tmp_size);
		e->lst = e->lst->next;
		e->i++;
	}
	return (true);
}
