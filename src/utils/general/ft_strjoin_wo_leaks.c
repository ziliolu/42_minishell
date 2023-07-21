/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_wo_leaks.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 17:09:13 by ialves-m          #+#    #+#             */
/*   Updated: 2023/07/21 11:59:09 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char	*ft_strjoin_wo_leaks(char* s1, char* s2)
{
	char *str;

	str = NULL;
	if (!s1)
	{
		s1 = ft_strdup(s2);
		return (s1);
	}
	else
	{
		// if (str)
		// 	free (str);
		str = ft_strjoin(s1, s2);
		free(s1);
		return (str);
	}
}
