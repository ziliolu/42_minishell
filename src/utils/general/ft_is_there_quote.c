/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_there_quote.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:02:43 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/21 11:58:54 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

bool ft_is_there_quote(char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		if(str[i] == '\"' || str[i] == '\'')
			return (true);
		i++;
	}
	return (false);
}