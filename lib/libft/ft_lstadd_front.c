/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- < lpicoli-@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:35:41 by root              #+#    #+#             */
/*   Updated: 2022/11/25 10:01:12 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	new->next = *lst;
	*lst = new;
}

/* void freeList(t_list *head)
{
	t_list  *tmp;
	while (head)
	{
		tmp = head;
		head = head->next;
		tmp->content = NULL;
		free(tmp);
    }
}

int main()
{
	t_list *first;
	t_list *second;
	t_list *third;
	
	int a = 4;
	int b = 5;
	int c = 6;

	first = ft_lstnew((void *)&a);
	second = ft_lstnew((void *)&b);
	third = ft_lstnew((void *)&c);
	
	first->next = second;
	ft_lstadd_front(&first, third);
	
	while (third)
	{
		printf("%d", *(int *)third->content);
		third = third->next;
	}
	freeList(third);
} */