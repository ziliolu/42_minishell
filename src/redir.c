/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 12:59:17 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/06/15 15:24:54 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void ft_init_fd(t_ms *ms)
{
    int i; 

    i = 0;
    while(i <= ms->n_pipes)
    {
        ms->cmds[i].fd[0] = STDIN_FILENO;
        ms->cmds[i].fd[1] = STDOUT_FILENO;
        i++;
    }
}

void ft_run_cmds(t_ms *ms)
{
    int i;

    i = 0;

    /* 
    */
    while(i <= ms->n_pipes)
    {
       ft_is_executable(ms, &ms->cmds[i]);
       i++;
    }
}