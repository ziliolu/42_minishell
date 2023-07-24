/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_broken_cmds_pipe.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 15:02:28 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/24 15:25:444 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_is_broken_cmds_pipe(t_ms *ms, char *str, t_broken_cmds *b)
{
	char *tmp_readline;
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
			if(ft_strcmp(b->prompt_tmp, "") != 0)
			{
				tmp_readline = ft_strtrim(b->prompt_tmp, " ");
				if(tmp_readline[0] == '|' || str[b->size] == '|')
				{
					ft_error(ms, "syntax error near unexpected token `|'", NULL, 2);
					ft_free(b->prompt_tmp);
					ft_free (tmp_readline);
					return (NULL);
				}
			}
			b->new_str = ft_strjoin(str, b->prompt_tmp);
			b->tmp = ft_strtrim(b->new_str, " ");
			ft_free (b->new_str);
		}
		ft_free(b->prompt_tmp);
		return (b->tmp);
	}
//}
