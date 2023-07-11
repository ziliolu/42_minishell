/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_args_validations.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 10:28:08 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/11 10:36:57 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include <stdbool.h>


bool ft_pipe_validation(t_elem *list)
{
    if(list->type == PIPE_LINE)
        return(ft_error("syntax error near unexpected token `|'"));
    return (true);   
}
bool ft_cmd_args_validation(t_ms *ms)
{
    
    t_elem *list;
    list = *ms->lexed_list;
    if(!ft_pipe_validation(list))
        return (false);
    return (true);
}