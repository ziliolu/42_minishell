/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_vars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 17:36:11 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/24 21:56:31 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char	*ft_strchr_vars(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (i != 0 && s[i] == c && i != (int)ft_strlen(s))
			return (s + i);
		i++;
	}
	return (0);
}
