/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 11:39:38 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/06/08 12:43:38 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	ft_print_list(t_env *list)
{
	while (list != NULL)
	{
		printf("Name: %s\nInfo: %s\nFull Info: %s\n", list->name, list->info, list->full_info);
		list = list->next;
		printf("\n");
	}
}

