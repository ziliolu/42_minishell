/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_arg_valid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 17:52:43 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/08/12 16:44:34 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

bool	ft_is_arg_valid(t_ms *ms, char *read_content)
{
	(void) ms;
	if (!ft_is_quote_valid(read_content))
		return (false);
	return (true);
}
