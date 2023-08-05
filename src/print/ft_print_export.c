/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_export.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:49:32 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/08/05 15:51:10 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_print_export(t_lst *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		if (ft_strchr_vars(lst->full_info, '='))
			printf("declare -x %s=\"%s\"\n", lst->name, lst->info);
		else
			printf("declare -x %s\n", lst->name);
		lst = lst->next;
		i++;
	}
}
