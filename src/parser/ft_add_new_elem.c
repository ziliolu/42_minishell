/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_new_elem.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:38:25 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/06/06 17:03:37 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_add_new_elem(t_elem **head, char *str, enum e_token)
{
	t_elem	*new;
	t_elem	*last;

	new = ft_new_elem(str);
	last = ft_find_last_elem(*head);
	last->next = new;
}

t_elem	*ft_new_elem(char *str)
{
	t_elem	*node;

	node = (t_elem *)malloc(sizeof(t_elem));
	if (node)
	{
        node->data = str;
        node->len = ft_strlen(str);
        node->next = NULL;
		return (node);
	}
	free (node);
	return (NULL);
}

t_elem	*ft_find_last_elem(t_elem *list)
{
	while (list->next != NULL)
		list = list->next;
	return (list);
}