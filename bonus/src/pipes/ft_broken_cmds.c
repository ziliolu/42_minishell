/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_broken_cmds.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 15:02:28 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/25 00:14:23 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_broken_cmds(t_ms *ms, char *str)
{
	t_broken_cmds	b;

	b.size = ft_strlen(str) - 1;
	b.prompt_tmp = NULL;
	b.new_str = NULL;
	b.tmp = NULL;
	b.prompt = "> ";
	if (str[0] == '|' || (str[b.size] == '|' && str[b.size - 1] == '|'))
	{
		ft_error(ms, "syntax error near unexpected token `|'", NULL, 2);
		return (NULL);
	}
	if (str[b.size] == '|')
	{
		b.size--;
		while (str[b.size] == ' ')
			b.size--;
		return (ft_is_broken_cmds_pipe(ms, str, &b));
	}
	return (ft_strdup(str));
}
