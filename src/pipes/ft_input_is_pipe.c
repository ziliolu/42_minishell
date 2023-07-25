/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input_is_pipe.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 00:10:14 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/25 11:59:00 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool	ft_input_is_pipe(t_ms *ms, char **tmp, char *str, t_broken_cmds *b)
{
	if (ft_strcmp(b->prompt_tmp, "") != 0)
	{
		*tmp = ft_strtrim(b->prompt_tmp, " ");
		if (*tmp[0] == '|' || str[b->size] == '|')
		{
			ft_error(ms, "syntax error near unexpected token `|'", NULL, 2);
			ft_free(b->prompt_tmp);
			ft_free (*tmp);
			return (true);
		}
		ft_free (*tmp);
	}
	return (false);
}
