/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_close_file_descriptors.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 11:07:56 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/15 12:00:12 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include <stdio.h>

void ft_close_pipes(t_ms *ms)
{
    int i;

    i = 0;
    while(ms->cmds[i].args)
    {
        if(ms->cmds[i].type == PIPE_LINE)
        {
            close(ms->cmds[i].fd[0]);
            close(ms->cmds[i].fd[1]);
        }
        i++;
    }
} 