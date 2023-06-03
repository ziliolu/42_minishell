/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 18:09:55 by root              #+#    #+#             */
/*   Updated: 2023/06/03 17:17:58 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new_lst)
{
	t_list	*last;

	last = *lst;
	if (!lst || ! new_lst)
		return ;
	if (!*lst)
	{
		*lst = new_lst;
		return ;
	}
	while (last->next)
		last = last->next;
	last->next = new_lst;
}

/*int main()
{
    int a = 1;
    int b = 2;
    int c = 3;

    t_list *first;
    t_list *second;
    t_list *third;

    first = ft_lstnew(&a);
    second = ft_lstnew(&b);
    third = ft_lstnew(&c);

    first->next = second;
    second->next = NULL;

    ft_lstadd_back(&first, third);
    
    while(first)
    {
        printf("%d\n", *(int *)first->content);
        first = first->next;
    }    
}*/