/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer_if_str_else.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:50:18 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/27 23:17:09 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_lexer_if_str_else(t_lexer *x, t_elem **elem_head, \
	char *str, enum e_status *status)
{
	if (str[x->i] == '$' && (ft_is_valid_character(str[x->i + 1])
			|| str[x->i + 1] == '?'))
	{
		ft_add_new_elem(elem_head, ft_new_elem(str + x->i, \
ft_count_char_env(str + x->i), ENV, status));
		x->i = x->i + ft_count_char_env(str + x->i) - 1;
	}
	else if (str[x->i] == '$' && !str[x->i + 1])
		ft_add_new_elem(elem_head, ft_new_elem(str + x->i, 1, \
WORD, status));
	else
	{
		ft_add_new_elem(elem_head, ft_new_elem(str + x->i, \
ft_count_char(str + x->i), WORD, status));
		x->i = x->i + ft_count_char(str + x->i) - 1;
	}
}
