/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_local_variables.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:29:10 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/22 18:00:54 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_print_local_variables(t_lst **head)
{
	t_lst	*lst;
	int		i;

	lst = NULL;
	if (*head)
		lst = *head;
	i = 0;
	while (lst != NULL)
	{
		printf("[%d] %s=%s\n", i, lst->name, lst->info);
		i++;
		lst = lst->next;
	}
}
