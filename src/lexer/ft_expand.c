/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 12:54:35 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/06/12 12:54:58 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_expand(t_env *list, char *variable)
{
	char	*str;
    
	str = ft_strtrim(variable, "$");
	while (list)
	{
		if (ft_strcmp(str, list->name))
			return (list->info);
		list = list->next;
	}
	return (NULL);
}