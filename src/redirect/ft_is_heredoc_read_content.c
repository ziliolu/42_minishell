/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_heredoc_read_content.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 10:01:08 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/08/02 18:31:45 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_is_heredoc_read_content(t_ms *ms, t_command *cmd, t_heredoc *h)
{
	char	*tmp;

	tmp = NULL;
	ms->pid = fork();
	if (ms->pid == 0)
	{
		g_exit_status = 0;
		while (ft_strcmp(h->read_content, h->eof) != 0)
		{
			ft_free(h->read_content);
			h->read_content = readline(h->prompt);
			if (ft_is_ctrld(cmd, h, &tmp) || g_exit_status == 130)
				return (h->str);
			else
			{
				if (ft_strcmp(h->read_content, h->eof) == 0)
				{
					//h->str = ft_strdup(h->read_content);
					break ;
				}
				ft_join_heredoc_inputs(ms, h, &tmp);
			}
		}
	}
	ft_free(h->read_content);
	ft_free(tmp);
	return (h->str);
}
