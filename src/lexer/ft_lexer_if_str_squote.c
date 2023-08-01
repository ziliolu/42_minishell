/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer_if_str_squote.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:50:18 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/25 11:59:01 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_lexer_if_str_squote(t_lexer *x, t_elem **elem_head, \
	char *str, enum e_status *status)
{
	if (x->squote_flag == 0 && x->dquote_flag == 0)
	{
		x->squote_flag = 1;
		*status = GENERAL;
		ft_add_new_elem(elem_head, ft_new_elem(str + x->i, 1, \
			SINGLE_QUOTE, status));
		*status = IN_SQUOTE;
	}
	else if (x->squote_flag == 1 && x->dquote_flag == 0)
	{
		x->squote_flag = 0;
		*status = GENERAL;
		ft_add_new_elem(elem_head, ft_new_elem(str + x->i, 1, \
			SINGLE_QUOTE, status));
	}
	else
		ft_add_new_elem(elem_head, ft_new_elem(str + x->i, 1, \
			SINGLE_QUOTE, status));
}
