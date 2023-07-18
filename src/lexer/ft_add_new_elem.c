/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_new_elem.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:38:25 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/18 12:01:35 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include <stdbool.h>

void	ft_add_new_elem(t_elem **head, t_elem *new_elem)
{
	t_elem	*new;
	t_elem	*last;

	new = new_elem;

	if(*head == NULL)
		*head = new_elem;
	else 
	{
		last = ft_find_last_elem(*head); // *head == > 
		last->next = new;
	}
	
	// if(ft_size_list(head) > 1)
	// {
	// 	last = ft_find_last_elem(*head); // *head == > 
	// 	last->next = new;
	// }
	
}

t_elem	*ft_new_elem(char *str, int len, enum e_token type, enum e_status status)
{
	t_elem	*node;
	char	*str_tmp;

	str_tmp = ft_strndup(str, len);
	node = (t_elem *)ft_calloc(1, sizeof(t_elem));
	if (node)
	{
		if (ft_strrchr(str_tmp, '\\') && status == GENERAL)
			node->data = ft_chartrim_wo_dquotes(str_tmp, '\\');
		else if (ft_strrchr(str_tmp, '\\') && status == IN_DQUOTE)
			node->data = ft_chartrim_w_dquotes(str_tmp, '\\');
		else
			node->data = ft_strdup(str_tmp);
        node->len = ft_strlen(node->data);
        node->next = NULL;
		node->status = status;
		node->type = type;
		free(str_tmp);
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