/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 10:52:56 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/06/07 10:58:06 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char *ft_strndup(char *str, int n)
{
	char *new_str;
	int i;
	
	new_str = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if(!new_str)
		return (NULL);
	i = 0;
	while(str[i] && i < n)
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';
	return (str);
}