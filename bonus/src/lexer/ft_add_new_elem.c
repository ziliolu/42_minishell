/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_new_elem.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:38:25 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/24 23:58:32 by lpicoli-         ###   ########.fr       */
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
