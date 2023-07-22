/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_broken_cmds_pipe.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 15:02:28 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/22 15:04:46 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_is_broken_cmds_pipe(t_ms *ms, char *str, t_broken_cmds *b)
{
	if (str[b->size] == '|')
	{
		ft_error(ms, "syntax error near unexpected token `|'", NULL);
		return (NULL);
	}
	else
	{
		while (!b->prompt_tmp || (b->prompt_tmp && \
			ft_strcmp(b->prompt_tmp, "") == 0))
		{
			ft_free(b->tmp);
			ft_free(b->prompt_tmp);
			b->prompt_tmp = readline(b->prompt);
			b->new_str = ft_strjoin(str, b->prompt_tmp);
			b->tmp = ft_strtrim(b->new_str, " ");
			ft_free (b->new_str);
		}
		ft_free(b->prompt_tmp);
		return (b->tmp);
	}
}
