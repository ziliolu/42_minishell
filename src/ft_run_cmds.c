/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_cmds.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 10:01:08 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/06/16 18:29:29 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void ft_run_cmds(t_ms *ms)
{
    int i;
    int k;

    i = 0;
    k = 0;
    while(i <= ms->n_pipes)
    {
        if(ms->cmds[i].redirs[k].arg != NULL)
        {
            while(k < ft_count_redirs_cmd(&ms->cmds[i]))  
            {
                open(ms->cmds[i].redirs[k].arg, O_CREAT | O_TRUNC | O_WRONLY, 0777);
                k++;
            }
            if(ms->cmds[i].redirs[k - 1].type == REDIR_OUT)
                ms->cmds[i].out = open(ms->cmds[i].redirs[k - 1].arg, O_CREAT | O_TRUNC | O_WRONLY, 0777);
            else if(ms->cmds[i].redirs[k - 1].type == D_REDIR_OUT)
                ms->cmds[i].out = open(ms->cmds[i].redirs[k - 1].arg, O_CREAT | O_APPEND | O_WRONLY, 0777);
        }
       ft_is_executable(ms, &ms->cmds[i]);
       i++;
    }
}

int ft_count_cmds(t_ms *ms)
{
    int i;
    
    i = 0;
    while(ms->cmds[i].args != NULL)
    {
        i++;
    }
    return (i);
}