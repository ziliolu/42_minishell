/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chartrim copy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 12:15:22 by ialves-m          #+#    #+#             */
/*   Updated: 2023/07/24 22:20:17 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	ft_chartrim_w_dquotes_while(t_trim *t, char *str, char c)
{
	while (str[t->i])
	{
		if (str[t->i] != c)
			t->tmp[t->j++] = str[t->i];
		else if (str[t->i] == c)
		{
			t->tmp[t->j++] = str[t->i];
			if (str[t->i + 1] == '\\')
				t->i++;
		}
		t->i++;
	}
}
