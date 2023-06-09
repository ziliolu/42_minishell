/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tokens.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 12:43:51 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/06/09 11:38:19 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include <unistd.h>

void	ft_print_tokens(t_elem *list)
{
    printf("-----------------------------------------------------------------------------------------\n");
    printf("|\tdata\t\t|\tlen\t|\tstatus  \t|\ttype    \t|\t\n");
    printf("-----------------------------------------------------------------------------------------\n");
	while (list != NULL)
	{
		printf("|\t'%s'\t\t|\t%d\t|\t%s  \t|\t%s    \t|\t", \
        list->data, list->len, ft_token_status(list->status), ft_token_type(list->type));
		list = list->next;
		printf("\n");
	}
	printf("-----------------------------------------------------------------------------------------\n");
}

char *ft_token_status(enum e_status status)
{
    if(status == GENERAL)
        return ("general");
    else if(status == IN_DQUOTE)
        return ("in_dquote");
    else
        return ("in_squote");
}

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