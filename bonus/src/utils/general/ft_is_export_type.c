/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_export_type.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 16:22:22 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/24 21:55:00 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

bool	ft_is_export_type(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (((str[i] == ' ' || str[i] == '\t') && (str[i - 1] == '='))
			|| ((ft_strchr_vars(str, '=') == 0 || ft_strchr_vars(str, '=') != 0)
				&& !ft_is_there_space(str)))
			return (true);
		i++;
	}
	return (false);
}
