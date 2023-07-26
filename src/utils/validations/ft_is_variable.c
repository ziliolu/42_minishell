/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 23:41:22 by ialves-m          #+#    #+#             */
/*   Updated: 2023/07/21 11:57:37 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

bool	ft_is_variable(t_ms *ms)
{
	int	j;
	int	pos;

	j = 0;
	pos = 0;
	printf("is a variable! \n");
	while (ft_is_valid_character(ms->ms_argv[0][j]))
		j++;
	if (ms->ms_argv[0][j] == '=')
		pos = j;
	if (pos == 0)
		return (false);
	printf("valid info:: %d\n", ft_is_valid_info(ms, pos + 1));
	return (true);
}
