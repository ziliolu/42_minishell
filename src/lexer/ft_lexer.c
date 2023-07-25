/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:44:30 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/25 11:59:00 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_lexer(t_ms *ms, char *str)
{
	enum e_status	status;
	t_elem			**elem_head;
	t_lexer			x;

	(void) ms;
	status = GENERAL;
	x.squote_flag = 0;
	x.dquote_flag = 0;
	elem_head = (t_elem **)ft_calloc(1, sizeof(t_elem *));
	x.i = 0;
	while (str[x.i])
	{
		ft_lexer_if_while_str(&x, elem_head, str, &status);
		if (!str[x.i + 1])
			break ;
		x.i++;
	}
	ms->lexed_list = elem_head;
}
