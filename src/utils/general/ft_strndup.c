/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 10:52:56 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/21 11:59:13 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char *ft_strndup(char *str, int n)
{
	char *new_str;
	int i;
	
	new_str = ft_calloc(n + 1, sizeof(char));
	if(!new_str)
		return (NULL);
	i = 0;
	while(i < n)
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}