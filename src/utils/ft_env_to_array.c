/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_to_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 16:03:14 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/03 10:28:19 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char **ft_env_to_array(t_ms *ms)
{
	int		size;
	int		i;
	int		tmp_size;
	char	**array;
	t_env	*list;
	
	i = 0;
	size = 0;
	list = ms->ms_env;
	while (list != NULL)
	{	
		size++;
		list = list->next;
	}
	list = ms->ms_env;
	array = (char **)ft_calloc(size + 1, sizeof(char *));
	if (array)
	{
		array[size] = NULL;
		while (i < size)
		{
			tmp_size = ft_strlen(list->full_info);
			array[i] = (char *)ft_calloc(tmp_size, sizeof(char));
			if (!array[i])
				return (NULL);
			ft_strlcpy(array[i], list->full_info, tmp_size);
			list = list->next;
			i++;
		}
	}
	//ft_print_array(array);
	return (array);
}

void ft_print_array(char **str)
{
	int i;

	i = 0;
	while(str[i])
	{
		printf("%s\n", str[i]);
		i++;
	}
}