/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_broken_cmds.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 15:02:28 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/11 11:36:48 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_broken_cmds(char *str)
{
	int		size;
	char	*prompt;
	char	*prompt_tmp;
    char	*new_str;

	size = ft_strlen(str) - 1;
	prompt = "> ";
	if(str[0] == '|' || (str[size] == '|' && str[size - 1] == '|'))
	{
		ft_error("syntax error near unexpected token `|'");
		return(NULL);
	}
	if (str[size] == '|')
	{
		while(str[size] == ' ')
			size--;
		if(str[size] == '|')
		{
			ft_error("syntax error near unexpected token `|'");
			return(NULL);
		}
		prompt_tmp = readline(prompt);
		new_str = ft_strjoin(str, prompt_tmp);
        //free(str);
		return (new_str);
	}
	return (str);
}