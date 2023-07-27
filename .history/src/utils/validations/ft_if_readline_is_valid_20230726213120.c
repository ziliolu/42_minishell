/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_if_readline_is_valid.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 00:01:50 by ialves-m          #+#    #+#             */
/*   Updated: 2023/07/26 21:31:20 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	ft_if_readline_is_valid(t_ms *ms, char *read_content)
{
	if (read_content[0] != '\0' && ft_is_arg_valid(ms, read_content))
	{
		ft_lexer(ms, read_content);
		ms->ms_argv = ft_split(read_content, ' ');
		ft_count_args(ms, *ms->lexed_list);
		ft_parser(ms, *ms->lexed_list);
		if (ft_cmd_args_validation(ms) && char	*ft_is_broken_cmds_pipe(t_ms *ms, char *str, t_broken_cmds *b)
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
})
		{
			if (ms->is_print)
				ft_print_tokens(ms, *ms->lexed_list);
			if (!ms->dot_comma_flag)
				ft_run_cmds(ms);
			else
			{
				ft_error(ms, \
				"minishell: syntax error near unexpected token `;'", NULL, 2);
				ms->dot_comma_flag = false;
			}
		}
		ft_free_array(ms->ms_argv);
		ft_free_cmds(ms);
		free(ms->count_args);
		ft_free_elem_list(*ms->lexed_list);
		free(ms->lexed_list);
	}
}

// && ft_is_arg_valid(ms, read_content)