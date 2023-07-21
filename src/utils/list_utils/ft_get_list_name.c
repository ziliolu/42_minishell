/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_list_name.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 18:27:36 by ialves-m          #+#    #+#             */
/*   Updated: 2023/07/20 16:10:52 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char	*ft_get_list_name(char *set)
{
	int 	i;
	
	i = 0;
	while (set[i] && set[i] != '=')
		i++;
	return (ft_substr(set, 0, i));
}