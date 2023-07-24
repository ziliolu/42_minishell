/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_to_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 16:03:14 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/24 22:41:57 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char	**ft_list_to_array(t_ms *ms)
{
	t_env_to_array	e;

	e.i = 0;
	e.size = 0;
	e.lst = ms->ms_env;
	while (e.lst != NULL)
	{	
		e.size++;
		e.lst = e.lst->next;
	}
	e.lst = ms->ms_env;
	e.array = (char **)ft_calloc(e.size + 1, sizeof(char *));
	if (e.array)
	{
		e.array[e.size] = NULL;
		if (!ft_env_to_array_while(ms, &e))
			return (NULL);
	}
	return (e.array);
}
