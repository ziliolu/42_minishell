/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:50:57 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/06/13 11:51:06 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char *ft_token_type(enum e_token type)
{
    if (type == WORD)
        return ("word");
    else if (type == WHITE_SPACE)
        return ("w_space");
	else if (type == NEW_LINE)
		return ("new_line");
	else if (type == SINGLE_QUOTE)
		return ("s_quote");
	else if (type == DOUBLE_QUOTE)
		return ("d_quote");
	else if (type == ESCAPE)
		return ("escape");
    else if (type == ENV)
        return ("env\t");
    else if (type == PIPE_LINE)
        return ("pipeline");
    else if (type == REDIR_IN)
        return ("redir_in");
    else if (type == REDIR_OUT)
        return ("redir_out");
    else if (type == D_REDIR_OUT)
        return ("d_redir_out");
    else if (type == HERE_DOC)
        return ("here_doc");
	else
		return (NULL);
}