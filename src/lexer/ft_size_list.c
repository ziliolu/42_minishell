/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ copy 4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:50:18 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/21 22:03:01 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_size_list(t_elem **header)
{
	int		i;
	t_elem	*list;

	i = 0;
	list = *header;
	while (list != NULL)
	{
		i++;
		list = list->next;
	}
	return (i);
}
