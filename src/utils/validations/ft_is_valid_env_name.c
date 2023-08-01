/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_valid_env_name.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 23:41:22 by ialves-m          #+#    #+#             */
/*   Updated: 2023/07/29 00:37:22 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

bool	ft_is_valid_env_name(t_ms *ms, char *str)
{
	int	i;

	(void) ms;
	i = 0;
	if (!str)
		return (false);
	if (!((str[i] >= 'a' && str[i] <= 'z')
			|| (str[i] >= 'A' && str[i] <= 'Z') || (str[i] == '_')))
		return (false);
	i++;
	while (str[i] != '=' && str[i] != '\0')
	{
		if ((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'A' && str[i] <= 'Z')
			|| (str[i] >= 'a' && str[i] <= 'z') || str[i] == '_')
			i++;
		else
			return (false);
	}
	return (true);
}
