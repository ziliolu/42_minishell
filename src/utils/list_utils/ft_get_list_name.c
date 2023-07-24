/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_list_name.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 18:27:36 by ialves-m          #+#    #+#             */
/*   Updated: 2023/07/24 21:21:50 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char	*ft_get_list_name(char *set)
{
	int	i;

	i = 0;
	while (set[i] && set[i] != '=')
		i++;
	return (ft_substr(set, 0, i));
}
