/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wait.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 00:02:28 by ialves-m          #+#    #+#             */
/*   Updated: 2023/07/21 16:33:42 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_wait(t_ms *ms)
{
	ms->status = 0;
	if (waitpid(ms->pid, &ms->status, 0) != -1)
	{
		if (WIFEXITED(ms->status))
			g_exit_status = WEXITSTATUS(ms->status);
		else if (WIFSIGNALED(ms->status) && g_exit_status == 0)
			g_exit_status = 128 + WTERMSIG(ms->status);
		ms->processes--;
	}
	while (ms->processes)
	{
		wait(0);
		ms->processes--;
	}
}
