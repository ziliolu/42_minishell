/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chartrim_wo_dquotes.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 12:15:22 by ialves-m          #+#    #+#             */
/*   Updated: 2023/07/24 22:25:46 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char	*ft_chartrim_wo_dquotes(char *str, char c)
{
	t_trim	t;

	t.i = 0;
	t.j = 0;
	t.tmp = ft_calloc(ft_strlen(str) + 1, sizeof(char));
	if (ft_strrchr(str, '\\'))
	{
		ft_chartrim_wo_dquotes_while(&t, str, c);
		return (t.tmp);
	}
	else
	{
		free (t.tmp);
		return (str);
	}
}
