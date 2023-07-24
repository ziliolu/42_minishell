/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_return_list_full_info.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 13:31:51 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/24 21:12:41 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char	*ft_return_list_full_info(t_lst *lst, char *name)
{
	while (lst)
	{
		if (ft_strcmp(lst->name, name) == 0)
			return (ft_strdup(lst->full_info));
		lst = lst->next;
	}
	return (NULL);
}
