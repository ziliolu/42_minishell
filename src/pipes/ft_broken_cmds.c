/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_broken_cmds.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 15:02:28 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/18 14:41:37 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_broken_cmds(t_ms *ms, char *str)
{
	int		size;
	char	*prompt;
	char	*prompt_tmp;
    char	*new_str;
	char *tmp;

	
	size = ft_strlen(str) - 1;
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
			prompt_tmp = readline(prompt);
			new_str = ft_strjoin(str, prompt_tmp);
			free(str);
			free(prompt_tmp);

			tmp = ft_strtrim(new_str, " ");
			free(new_str);
			printf("%s\n", new_str);
			////return (ft_strtrim(new_str, " "));
			}tmp
	return (str);
}
