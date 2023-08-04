/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_heredoc_read_content.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 10:01:08 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/08/04 10:49:58 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void ft_is_heredoc_read_content(t_ms *ms, t_command *cmd, t_heredoc *h)
{
	ms->pid = fork();
	if (ms->pid == 0)
	{
		//ft_close_pipes(ms);
		// if (ms->std_in > STDIN_FILENO)
		// 	close(ms->std_in);
		while (ft_strcmp(h->read_content, h->eof) != 0)
		{
			ft_free(h->read_content);
			h->read_content = readline(h->prompt);
			//if (ft_is_ctrld(cmd, h, &tmp) || g_exit_status == 130)
			// 	return (h->str);
			// else
			// {
			if (ft_strcmp(h->read_content, h->eof) == 0)
			{
				break ;
			}
			write(h->fd, h->read_content, ft_strlen(h->read_content));
			write(h->fd, "\n", 1);
		}
		ft_free(h->read_content);
		close(h->fd);
		open(h->str, O_RDONLY);
		exit(g_exit_status);
	}
	ft_signals_ignore();
	waitpid(0, NULL, 0);
	cmd->in = h->fd;
}

// void ft_is_heredoc_read_content(t_ms *ms, t_command *cmd, t_heredoc *h)
// {
// 	//char	*tmp;

// 	//tmp = NULL;
// 	h->fd = open(HEREDOC, O_WRONLY | O_CREAT | O_TRUNC, 0644);
// 	ms->pid = fork();
// 	if (ms->pid == 0)
// 	{
// 		ft_close_pipes(ms);
// 		//g_exit_status = 0;
// 		while (ft_strcmp(h->read_content, h->eof) != 0)
// 		{
// 			ft_free(h->read_content);
// 			h->read_content = readline(h->prompt);
// 			//if (ft_is_ctrld(cmd, h, &tmp) || g_exit_status == 130)
// 			// 	return (h->str);
// 			// else
// 			// {
// 			if (ft_strcmp(h->read_content, h->eof) == 0)
// 			{
// 				//h->str = ft_strdup(h->read_content);
// 				break ;
// 			}
// 			write(h->fd, h->read_content, ft_strlen(h->read_content));
// 				//ft_join_heredoc_inputs(ms, h, &tmp);
// 		}
// 		ft_free(h->read_content);
// 		cmd->in = h->fd;
// 		close(h->fd);
// 		exit(g_exit_status);
// 	}
// 	ft_signals_ignore();
// 	waitpid(0, NULL, 0);
// 		// if(h->str)
// 		// 	write(h->fd, h->str, ft_strlen(h->str));
// 		// write(h->fd, "\n", 1);
// 		// ft_free(h->str);
// 		// cmd->in = h->fd;

// 	//ft_free(tmp);
// 	//close (h->fd);
// 	//dup2(open(HEREDOC, O_RDONLY), STDIN_FILENO);
// 	//return (h->str);
// }
