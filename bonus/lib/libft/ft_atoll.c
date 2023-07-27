/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:43:55 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/27 12:17:29 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../../includes/minishell.h"

long long	ft_atoll(const char *nptr)
{
	long long	r;
	int			i;
	int			signal;

	r = 0;
	i = 0;
	signal = 1;
	while (ft_isspace(nptr[i]))
		i++;
	if (ft_isnegative(nptr[i]) || ft_ispositive(nptr[i]))
		if (ft_isnegative(nptr[i++]))
			signal = -1;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		r *= 10;
		r += nptr[i] - '0';
		i++;
	}
	return (r * signal);
}
