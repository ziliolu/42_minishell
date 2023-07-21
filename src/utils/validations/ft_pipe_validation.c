/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe_validation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 10:28:08 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/21 11:57:40 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

bool	ft_pipe_validation(t_ms *ms)
{
    t_elem *list = *ms->lexed_list;
    while (list)
    {
        if (list->type == PIPE_LINE)
        {
            while (list->next->type == WHITE_SPACE)
                list = list->next;
            if (list->next->type == PIPE_LINE)
                return (ft_error(ms, "syntax error near unexpected token `|'", NULL));
        }
        list = list->next;
    }
    return (true);
}
