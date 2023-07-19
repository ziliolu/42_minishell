/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_to_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 16:03:14 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/19 11:29:43 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char **ft_list_to_array(t_ms *ms)
{
	int		size;
	int		i;
	int		tmp_size;
	char	**array;
	t_lst	*lst;
	
	i = 0;
	size = 0;
	lst = ms->ms_env;

	// if(ms->ms_env_array)
	// 	ft_free_array(ms->ms_env_array);
	while (lst != NULL)
	{	
		size++;
		lst = lst->next;
	}
	lst = ms->ms_env;
	array = (char **)ft_calloc(size + 1, sizeof(char *));
	if (array)
	{
		array[size] = NULL;
		while (i < size)
		{
			tmp_size = ft_strlen(lst->full_info) + 1;
			array[i] = (char *)ft_calloc(tmp_size, sizeof(char));
			if (!array[i])
				return (NULL);
			ft_strlcpy(array[i], lst->full_info, tmp_size);
			lst = lst->next;
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