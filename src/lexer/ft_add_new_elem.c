/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_new_elem.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:38:25 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/06/07 10:52:45 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_add_new_elem(t_elem **head, t_elem *new_elem)
{
	t_elem	*new;
	t_elem	*last;

	new = new_elem;
	last = ft_find_last_elem(*head);
	last->next = new;
}

t_elem	*ft_new_elem(char *str, int len, enum e_token type, enum e_status status)
{
	t_elem	*node;

	node = (t_elem *)malloc(sizeof(t_elem));
	if (node)
	{
        node->data = ft_strndup(str, len);
        node->len = ft_strlen(str);
        node->next = NULL;
		node->status = status;
		node->type = type;
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

