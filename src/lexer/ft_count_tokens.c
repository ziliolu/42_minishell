/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_tokens.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 12:43:51 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/06/10 21:53:15 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_count_tokens(t_elem *list)
{
	int	counter;

	counter = 0;
	while (list != NULL)
	{
		list = list->next;
		counter += 1;
	}
	printf("|\t\t\t|\t%d total number of arguments in the element list.\t|\n", counter);
	printf("-----------------------------------------------------------------------------------------\n");
	return (counter);
}
