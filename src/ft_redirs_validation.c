/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirs_validation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 00:07:27 by ialves-m          #+#    #+#             */
/*   Updated: 2023/07/21 00:07:57 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

bool ft_redirs_validation(t_ms *ms)
{
    int i;
    int j;

    i = 0;
    j = 0;
    enum e_token type;
    char *arg;

    type = ms->cmds[i].redirs[j].type;
    arg = ms->cmds[i].redirs[j].arg;

    if(type && !arg)
        return false;
    while(ms->cmds[i].args)
    {
        j = 0;
        while(ms->cmds[i].redirs && ms->cmds[i].redirs[j].type)
        {
            if(ft_is_redir(type) && ft_is_arg_redir(arg))
            {
                ft_printf("minishell: syntax error near unexpected token `%s'\n", arg);
                g_exit_status = 2;
                return (false);
            }
            j++;
        }
        i++;
    }
    return (true);
}
