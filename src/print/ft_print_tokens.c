/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tokens.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 12:43:51 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/06/13 11:50:36 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_print_tokens(t_elem *list)
{
	t_elem *additional;

	additional = list;
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
	printf("|\t%d Pipes\t\t|\t%d total number of arguments in the element list.\t|\n", ft_count_pipes(additional), ft_count_tokens(additional));
	printf("-----------------------------------------------------------------------------------------\n");
}
