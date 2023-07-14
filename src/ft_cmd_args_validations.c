/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_args_validations.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 10:28:08 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/14 15:50:46 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"


bool ft_pipe_validation(t_ms *ms)
{
    t_elem *list = *ms->lexed_list;
    while(list)
    {
        if(list->type == PIPE_LINE)
        {
            while(list->next->type == WHITE_SPACE)
                list = list->next;
            if(list->next->type == PIPE_LINE)
                return(ft_error(ms, "syntax error near unexpected token `|'", NULL));
            //list = list->next;
        }
        list = list->next;
    }
    return (true);   

}

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
bool ft_cmd_args_validation(t_ms *ms)
{
    
    // t_elem *list;
    // list = *ms->lexed_list;
    if(!ft_redirs_validation(ms))
        return (false);
    if(!ft_pipe_validation(ms))
        return (false);
    return (true);
}