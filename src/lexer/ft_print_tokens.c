/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tokens.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 12:43:51 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/06/08 13:00:57 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include <unistd.h>

void	ft_print_tokens(t_elem *list)
{
    printf("-----------------------------------------------------------------\n");
    printf("|     data     |     lenght     |     status     |     type     |\n");
     printf("-----------------------------------------------------------------\n");
	while (list != NULL)
	{
		printf("|     '%s'          %d          %s          %s     ", \
        list->data, list->len, ft_token_status(list->status), ft_token_type(list->type));
		list = list->next;
		printf("\n");
	}
}

char *ft_token_status(enum e_status status)
{
    if(status == GENERAL)
        return ("GENERAL");
    else if(status == IN_DQUOTE)
        return ("IN_DQUOTE");
    else
        return ("IN_SQUOTE");
}

char *ft_token_type(enum e_token type)
{
    if(type == WORD)
        return("WORD");
    else if(type == WHITE_SPACE)
        return("WHITE_SPACE");
    else
        return ("OTHER");
        
}