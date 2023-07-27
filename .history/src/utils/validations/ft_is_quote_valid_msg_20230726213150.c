/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_quote_valid_msg.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 00:12:03 by ialves-m          #+#    #+#             */
/*   Updated: 2023/07/26 21:31:50 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

bool	ft_is_quote_valid_msg(char *read_content, int s_quote, int d_quote)
{
	(void) read_content;
	if (s_quote == 1 || d_quote == 1)
	{
		
		// printf("> minishell: unexpected EOF while looking for matching `%c'\n", \
		// 	ft_choose_quotes(s_quote, d_quote));
		// printf("minishell: syntax error: unexpected end of file\n");
		g_exit_status = 2;
		return (false);
	}
	return (true);
}

char	*ft_is_broken_cmds_pipe(t_ms *ms, char *str, t_broken_cmds *b)
{
	char	*tmp_readline;

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