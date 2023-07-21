/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_broken_cmds.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 15:02:28 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/21 10:27:17 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_broken_cmds(t_ms *ms, char *str)
{
	int		size;
	char	*prompt;
	char	*prompt_tmp;
    char	*new_str;
	char	*tmp;

	size = ft_strlen(str) - 1;
	prompt_tmp = NULL;
	new_str = NULL;
	tmp = NULL;
	prompt = "> ";
	if(str[0] == '|' || (str[size] == '|' && str[size - 1] == '|'))
	{
		ft_error(ms, "syntax error near unexpected token `|'", NULL);
		return(NULL);
	}
	if (str[size] == '|')
	{
		size--;
		while(str[size] == ' ')
			size--;
		if(str[size] == '|')
		{
			ft_error(ms, "syntax error near unexpected token `|'", NULL);
			return(NULL);
		}
		else
		{
			while(!prompt_tmp || (prompt_tmp && ft_strcmp(prompt_tmp, "") == 0))
			{
				ft_free(tmp);
				ft_free(prompt_tmp);
				prompt_tmp = readline(prompt);
				new_str = ft_strjoin(str, prompt_tmp);
				tmp = ft_strtrim(new_str, " ");	
				ft_free (new_str);
			}
			ft_free(prompt_tmp);
			return (tmp);
		}
	}
	return (ft_strdup(str));
}

;