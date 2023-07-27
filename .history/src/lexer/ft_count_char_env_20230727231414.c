/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_char_env.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:50:18 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/27 23:14:14 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool	ft_is_not_valid(char c)
{
	if(c == WHITE_SPACE || c == PIPE_LINE
	|| c == SINGLE_QUOTE || c == DOUBLE_QUOTE
	|| c == '\0')
		return (true);
	return (false);
}
// int	ft_count_char_env(t_ms *ms, char *str)
// {
// 	int	i;
// 	char *new_str;
// 	char *tmp;
	
// 	tmp = NULL;
// 	new_str = NULL;
// 	i = 0;

// 	while(str[i])
// 	{

// 		tmp =  ft_charjoin(new_str, str[i]);
// 		ft_free(new_str);
// 		new_str = strdup(tmp);
// 		ft_free(tmp);
// 		if(ft_is_not_valid(str[i]) || ft_is_already_in_list(new_str + 1, ms->ms_env) 
// 			|| ft_is_already_in_list(new_str + 1, *ms->vars) || str[i] == '?')
// 			return (i + 1);
// 		i++;
// 	}
// 	return (i);
// 	// i++;
// 	// while (str[i] != WHITE_SPACE && str[i] != PIPE_LINE
// 	// 	&& str[i] != SINGLE_QUOTE && str[i] != DOUBLE_QUOTE
// 	// 	&& ft_valid_env(str[i]) && str[i] != '\0')
// 	// {
// 	// 	i++;
// 	// }
// 	// return (i);
// }

//bool	ft_is_already_in_list(char *name, t_lst *list)

int	ft_count_char_env(char *str)
{
	int	i;

	i = 0;
	i++;
	while (str[i] != WHITE_SPACE && str[i] != PIPE_LINE
		&& str[i] != SINGLE_QUOTE && str[i] != DOUBLE_QUOTE
		&& ft_valid_env(str[i]) && str[i] != '\0')
	{
		if(str[i] == '?' && str[i - 1] == '$')
			return (i + 1);
		i++;
	}
	return (i);
}
