/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_return_list_info.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 13:31:51 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/25 11:21:41 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char	*ft_return_list_info(t_lst *lst, char *name)
{
	while (lst)
	{
		if (ft_strcmp(lst->name, name) == 0)
			return (ft_strdup(lst->info));
		lst = lst->next;
	}
	return (NULL);
}
