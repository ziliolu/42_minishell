/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_absolute_path.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 23:51:05 by ialves-m          #+#    #+#             */
/*   Updated: 2023/07/21 11:54:04 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool	ft_is_absolute_path(char *str)
{
	if (!str)
		return (false);
	if (str[0] == '/' || (str[0] == '.' && str[1] == '/')
		|| (str[0] == '.' && str[1] == '.' && str[2] == '/')
		|| (str[0] == '~' && str[1] == '/'))
		return (true);
	return (false);
}
