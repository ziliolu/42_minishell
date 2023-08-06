/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer_if_while_str.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:50:18 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/08/06 11:03:50 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_lexer_if_while_str(t_lexer *x, t_elem **elem_head, \
	char *str, enum e_status *status)
{
	if (str[x->i] == WHITE_SPACE && *status != GENERAL)
		ft_add_new_elem(elem_head, ft_new_elem(str + x->i, 1, \
			WHITE_SPACE, status));
	else if (str[x->i] == SINGLE_QUOTE)
		ft_lexer_if_str_squote(x, elem_head, str, status);
	else if (str[x->i] == DOUBLE_QUOTE)
		ft_lexer_if_str_dquote(x, elem_head, str, status);
	else if (str[x->i] == PIPE_LINE)
		ft_add_new_elem(elem_head, ft_new_elem(str + x->i, 1, \
			PIPE_LINE, status));
	else if (str[x->i] == REDIR_IN)
		ft_lexer_if_str_redir_in(x, elem_head, str, status);
	else if (str[x->i] == REDIR_OUT)
		ft_lexer_if_str_redir_out(x, elem_head, str, status);
	else if (str[x->i] == WHITE_SPACE)
		ft_add_new_elem(elem_head, ft_new_elem(str + x->i, 1, \
			WHITE_SPACE, status));
	else
		ft_lexer_if_str_else(x, elem_head, str, status);
}
