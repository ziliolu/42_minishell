/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tokens.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 12:43:51 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/26 19:34:42 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_print_tokens(t_ms *ms, t_elem *list)
{
	t_elem	*additional;

	additional = list;
	printf("-----------------------------------------------------\
------------------------------------\n");
	printf("|\tdata\t\t|\tlen\t|\tstatus  \t|\ttype    \t|\t\n");
	printf("-----------------------------------------------------\
------------------------------------\n");
	while (list != NULL)
	{
		printf("|\t'%s'\t\t|\t%d\t|\t%s  \t|\t%s    \t|\t", \
		list->data, list->len, ft_token_status(list->status), \
			ft_token_type(list->type));
		list = list->next;
		printf("\n");
	}
	printf("-----------------------------------------------------\
------------------------------------\n");
	printf("|\t%d Pipes\t\t|\t%d total number of arguments in the \
element list.\t|\n", ft_count_pipes(additional), \
			ft_count_tokens(additional));
	printf("-------------------------------------------------------\
----------------------------------\n");
	ft_print_command_nodes(ms, ms->n_pipes);
}
