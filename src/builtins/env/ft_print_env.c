/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 11:39:38 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/06/28 10:24:23 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	ft_print_env(t_ms *ms)
{
	t_env *list;

	list = ms->ms_env;
	while (list != NULL)
	{	
		printf("%s\n", list->full_info);
		list = list->next;
	}
}

