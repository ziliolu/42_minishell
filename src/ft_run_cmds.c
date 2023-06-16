/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_cmds.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 10:01:08 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/06/16 10:19:02 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void ft_run_cmds(t_ms *ms)
{
    int i;

    i = 0;
    while(i <= ms->n_pipes)
    {
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