/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_heredoc_read_content.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 10:01:08 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/31 09:30:41 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_is_heredoc_read_content(t_command *cmd, t_heredoc *h)
{
	int pid;
	int status;

	status = 0;
	
	//ft_signals_broken_cmds();
	ft_signals_broken_cmds();
	pid = fork();
	if(pid == 0)
	{
		g_exit_status = 0;
		while (ft_strcmp(h->read_content, h->eof) != 0 || g_exit_status != 130)
		{
			if(g_exit_status == 130)
				exit(g_exit_status);
			h->read_content = readline(h->prompt);
			//printf("g: %d", g_exit_status);
			if (!h->read_content)
			{
				cmd->err = true;
				printf("\n");
				return (NULL);
			}
			else
			{
				if (ft_strcmp(h->read_content, h->eof) == 0)
					break ;
				h->str = ft_strjoin(h->str, h->read_content);
				h->str = ft_strjoin(h->str, "\n");
			}
		}
		exit(0);
	}
	else
	{
		printf("teste\n");
		waitpid(pid, &status, 0);
		//ft_handle_signals();
		
	}
	return (h->str);
}
