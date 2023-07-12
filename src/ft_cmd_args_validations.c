/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_args_validations.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 10:28:08 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/12 11:13:21 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"


// bool ft_pipe_validation(t_elem *list)
// {
//     // if(list->type == PIPE_LINE)
//     //     return(ft_error("syntax error near unexpected token `|'"));
//     // return (true);   

    
// }

bool ft_redirs_validation(t_ms *ms)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while(ms->cmds[i].args)
    {
        j = 0;
        while(ms->cmds[i].redirs && ms->cmds[i].redirs[j].type)
        {
            if((ms->cmds[i].redirs[j].type == D_REDIR_OUT) && \
            ((ft_strcmp(ms->cmds[i].redirs[j].arg, ">") == 0) || ft_strcmp(ms->cmds[i].redirs[j].arg, ">>") == 0))
                return(ft_error(ms, "syntax error near unexpected token `>'", NULL));
            else if((ms->cmds[i].redirs[j].type == REDIR_OUT) && \
            ((ft_strcmp(ms->cmds[i].redirs[j].arg, ">") == 0) || ft_strcmp(ms->cmds[i].redirs[j].arg, ">>") == 0))
                return(ft_error(ms, "syntax error near unexpected token `>'", NULL));
            j++;
        }
        i++;
    }
    return (true);
}
bool ft_cmd_args_validation(t_ms *ms)
{
    
    t_elem *list;
    list = *ms->lexed_list;
    if(!ft_redirs_validation(ms))
        return (false);
    return (true);
}