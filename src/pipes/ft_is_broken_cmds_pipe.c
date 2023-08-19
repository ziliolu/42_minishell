/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_broken_cmds_pipe.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 00:01:54 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/08/13 08:04:28 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_is_broken_cmds_pipe(t_ms *ms, char *str, t_broken_cmds *b)
{
	char	*tmp_readline;

	b->prompt = "> ";
	while (!b->prompt_tmp || (b->prompt_tmp && \
		ft_strcmp(b->prompt_tmp, "") == 0))
	{
		ft_free(b->tmp);
		ft_free(b->prompt_tmp);
		b->prompt_tmp = readline(b->prompt);
		if (!b->prompt_tmp)
		{
			printf("minishell: syntax error: unexpected end of file\n");
			return ("exit");
		}
		if (ft_input_is_pipe(ms, &tmp_readline, str, b))
			return (NULL);
		b->new_str = ft_strjoin(str, b->prompt_tmp);
		b->tmp = ft_strtrim(b->new_str, " ");
		ft_free (b->new_str);
	}
	ft_free(b->prompt_tmp);
	return (b->tmp);
}
