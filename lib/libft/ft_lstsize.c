/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- < lpicoli-@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 18:27:59 by root              #+#    #+#             */
/*   Updated: 2022/11/25 10:03:29 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

/*int main()
{
	t_list *first;
	t_list *second;
	t_list *third;

	int a = 1;
	int b = 2; 
	int c = 3;

	first = ft_lstnew(&a);
	second = ft_lstnew(&b);
	third = ft_lstnew(&c);

	first->next = second;
	second->next = third;
	third->next = NULL;

	printf("number of nodes: %d\n", ft_lstsize(first));
}*/