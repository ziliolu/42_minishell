/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_in_llong_range.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 13:55:38 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/08/12 07:30:17 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	ft_return_signal(char c, int signal)
{
	if (ft_isnegative(c) || ft_ispositive(c))
		if (ft_isnegative(c))
			signal = -1;
	return (signal);
}

int	ft_bigger_llong_max(char *nptr)
{
	int	size;

	size = ft_strlen(nptr);
	return (size);
}

bool	ft_is_in_llong_range(char *nptr)
{
	unsigned long long	r;
	int					i;
	int					signal;

	r = 0;
	i = 0;
	signal = 1;
	while (ft_isspace(nptr[i]))
		i++;
	ft_return_signal(nptr[i++], signal);
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		r *= 10;
		r += nptr[i] - '0';
		i++;
	}
	if (signal == -1)
	{
		if (r <= LLONG_MAX || ft_strcmp(nptr, "-9223372036854775808") == 0)
			return (true);
		return (false);
	}
	if (r > LLONG_MAX || ft_bigger_llong_max(nptr) > 19)
		return (false);
	return (true);
}
