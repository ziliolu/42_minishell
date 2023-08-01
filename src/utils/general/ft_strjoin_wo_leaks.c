/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_wo_leaks.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 17:09:13 by ialves-m          #+#    #+#             */
/*   Updated: 2023/07/24 22:43:18 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char	*ft_strjoin_wo_leaks(char *s1, char *s2)
{
	char	*str;

	str = NULL;
	if (!s1)
	{
		s1 = ft_strdup(s2);
		return (s1);
	}
	else
	{
		str = ft_strjoin(s1, s2);
		return (str);
	}
}
