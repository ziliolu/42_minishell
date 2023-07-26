/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:43:55 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/26 12:45:59 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// long long	ft_atoll(const char *nptr)
// {
// 	long long	r;
// 	int	i;
// 	int	signal;

// 	r = 0;
// 	i = 0;
// 	signal = 1;
// 	while (ft_isspace(nptr[i]))
// 		i++;
// 	if (ft_isnegative(nptr[i]) || ft_ispositive(nptr[i]))
// 	{
// 		if (ft_isnegative(nptr[i++]))
// 		signal = -1;
// 	}
// 	while (nptr[i] >= '0' && nptr[i] <= '9')
// 	{
// 		r *= 10;
// 		r += nptr[i] - '0';
// 		i++;
// 	}
// 	return (r * signal);
// }

#include <limits.h>

long long ft_atoll(const char *nptr) {
    long long r;
    int i;
    int signal;

    r = 0;
    i = 0;
    signal = 1;

    while (ft_isspace(nptr[i]))
        i++;

    if (ft_isnegative(nptr[i]) || ft_ispositive(nptr[i])) {
        if (ft_isnegative(nptr[i++]))
            signal = -1;
    }

    while (nptr[i] >= '0' && nptr[i] <= '9') {
        // Check for overflow before multiplying by 10 and adding the new digit
        if (r > (LLONG_MAX - (nptr[i] - '0')) / 10) {
            // Overflow detected
            return (0);
        }

        r *= 10;
        r += nptr[i] - '0';
        i++;
    }

    return (r * signal);
}


/* int main()
{
    printf("%d\n", atoll("  +10"));
    printf("%d\n", ft_atoll("  +10"));
} */