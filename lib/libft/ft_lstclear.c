/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- < lpicoli-@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:52:28 by lpicoli-          #+#    #+#             */
/*   Updated: 2022/11/25 10:03:04 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Deletes and frees the given node and every
** successor of that node, using the function 
** ’del’ and free(3). Finally, the pointer to 
** the list must be set to NULL.
*/

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	if (!*lst || !del)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = tmp;
	}
}

/*void ft_freeNode(void *node)
{
    node = NULL;   
}

int main()
{
    int a = 1;
    int b = 2;
    
    t_list *first;
    t_list *second;

    first = ft_lstnew(&a);
    second = ft_lstnew(&b);
       
    first->next = second;
    second->next = NULL;

    while (first)
    {    
        printf("%d\n", *(int *)first->content);
        first = first->next;
    }
    
    ft_lstclear(&first, &ft_freeNode);
    
    if(first == NULL && second == NULL)
        printf("It's null");
    else
    {   
        printf("It's not null");
    }
}*/
