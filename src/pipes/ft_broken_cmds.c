/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_broken_cmds.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 15:02:28 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/06 15:14:53 by lpicoli-         ###   ########.fr       */
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
	if (str[size] == '|')
	{
		prompt_tmp = readline(prompt);
		new_str = ft_strjoin(str, prompt_tmp);
        //free(str);
		return (new_str);
	}
	return (str);
}