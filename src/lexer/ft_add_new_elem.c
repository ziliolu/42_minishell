/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_new_elem.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:38:25 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/21 22:15:49 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_add_new_elem(t_elem **head, t_elem *new_elem)
{
	t_elem	*new;
	t_elem	*last;

	new = new_elem;
	if (*head == NULL)
		*head = new_elem;
	else
	{
		last = ft_find_last_elem(*head);
		last->next = new;
	}	
}
