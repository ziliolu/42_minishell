/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_valid_env_name.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 23:41:22 by ialves-m          #+#    #+#             */
/*   Updated: 2023/07/26 05:44:45 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

bool	ft_is_valid_env_name(t_ms *ms, char *str)
{
	int	i;

	(void) ms;
	i = 0;
	if (str[i] >= 48 && str[i] <= 57)
		return (false);
	i++;
	while (str[i] != '=' && str[i] != '\0')
	{
		if ((str[i] >= 48 && str[i] <= 57) || (str[i] >= 65 && str[i] <= 90)
			|| (str[i] >= 97 && str[i] <= 122) || str[i] == '_')
			i++;
		else
			return (false);
	}
	return (true);
}
