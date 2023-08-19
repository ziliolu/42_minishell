/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signals_heredoc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 00:55:09 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/08/13 23:21:27 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_handler_heredoc(int signal, t_heredoc *ptr)
{
	static t_heredoc	*save = NULL;

	if (save == NULL)
		save = ptr;
	else if (signal == SIGINT)
	{
		printf("\n");
		g_exit_status = 130;
		ft_free(save->eof);
		ft_free(save->str);
		ft_free_env(save->ms->ms_env);
		ft_free_env(save->ms->export_list);
		ft_free_array(save->ms->paths);
		ft_free_array(save->ms->ms_env_array);
		ft_free_array(save->ms->ms_argv);
		free(save->ms->count_args);
		ft_free_elem_list(*save->ms->lexed_list);
		free(save->ms->lexed_list);
		free(save->ms->clean);
		ft_free_env(*save->ms->vars);
		free(save->ms->vars);
		ft_free_cmds(save->ms);
		exit(g_exit_status);
	}
}

void	ft_signals_heredoc(t_heredoc *ptr)
{
	signal(SIGINT, (void *)ft_handler_heredoc);
	ft_handler_heredoc(-1, ptr);
	signal(SIGQUIT, SIG_IGN);
}
