/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_heredoc_read_content.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 10:01:08 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/31 23:33:00 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_is_heredoc_read_content(t_ms *ms, t_command *cmd, t_heredoc *h)
{
	char *tmp;

	tmp = NULL;
	ms->pid = fork();
	if(ms->pid == 0)
	{
		g_exit_status = 0;
		while (ft_strcmp(h->read_content, h->eof) != 0)
		{
			ft_free(h->read_content);
			h->read_content = readline(h->prompt);
			if (!h->read_content)
			{
				cmd->err = true;
				printf("minishell: warning: here-document delimited by end-of-file (wanted `%s')\n", h->eof);
				ft_free(tmp);
				return(h->str);
			}
			else
			{
				if (ft_strcmp(h->read_content, h->eof) == 0)
					break ;
				if(!tmp)
				{
					tmp = ft_strdup(h->read_content);
					h->str = ft_strdup(h->read_content);
				}
				else
				{
					ft_free(h->str);
					h->str = ft_strjoin(tmp, "\n");
					ft_free(tmp);
					tmp = ft_strjoin(h->str, h->read_content);
					ft_free(h->str);
					h->str = ft_strdup(tmp);
				}
			}
		}
	}
	ft_free(h->read_content);
	ft_free(tmp);
	return (h->str);
}
