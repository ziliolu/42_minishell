/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_arg_valid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 17:52:43 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/21 11:57:17 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

bool ft_is_arg_valid(t_ms *ms, char *read_content)
{
    (void)ms;
	if(!ft_is_quote_valid(read_content))
		return (false);
    return (true);
}