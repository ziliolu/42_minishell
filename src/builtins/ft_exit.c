/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 13:05:23 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/13 12:13:09 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void ft_exit(t_ms *ms)
{
    int i;
    
    i = 0;
    if(ms->n_pipes == 0)
    {
        ft_printf("exit\n");
        //free(tmp_prompt);
        ft_free_env(ms);
        ft_free_array(ms->paths);
        if (ms->cmds[0].args[1])
            exit(ft_atoi(ms->cmds[0].args[1]));
        else
            exit(0);
    }
    else 
    {
        while(ms->cmds[i].args)
        {
            i++;
        }
        if(ms->cmds[i - 1].args[1])
            g_exit_status = ft_atoi(ms->cmds[i - 1].args[1]);
    }
    
}