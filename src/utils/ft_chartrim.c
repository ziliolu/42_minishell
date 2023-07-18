/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chartrim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 12:15:22 by ialves-m          #+#    #+#             */
/*   Updated: 2023/07/18 12:00:55 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_chartrim_w_dquotes(char *str, char c)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tmp = ft_calloc(ft_strlen(str) + 1, sizeof(char));
	if (ft_strrchr(str, '\\'))
	{
		while (str[i])
		{
			if (str[i] != c)
				tmp[j++] = str[i];
			else if (str[i] == c)
			{
				tmp[j++] = str[i];
				if (str[i+1] == '\\')
					i++;

			}
			i++;
		}
		//free (str);
		return (tmp);
	}
	else
	{
		free (tmp);	
		return (str);
	}
}

char	*ft_chartrim_wo_dquotes(char *str, char c)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tmp = ft_calloc(ft_strlen(str) + 1, sizeof(char));
	if (ft_strrchr(str, '\\'))
	{
		while (str[i])
		{
			if (str[i] != c)
				tmp[j++] = str[i];
			else if (str[i + 1] == c)
			{
				tmp[j++] = str[i+1];
				i++;
			}
			i++;
		}
		return (tmp);
	}
	else
	{
		free (tmp);
		return (str);
	}
}
