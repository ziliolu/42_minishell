/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer_if_str_redir_out.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:50:18 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/22 14:03:22 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_lexer_if_str_redir_out(t_lexer *x, t_elem **elem_head, \
	char *str, enum e_status status)
{
	if (str[x->i + 1] == REDIR_OUT)
	{
		ft_add_new_elem(elem_head, ft_new_elem(str + x->i, 2, \
			D_REDIR_OUT, status));
		x->i++;
	}
	else
		ft_add_new_elem(elem_head, ft_new_elem(str + x->i, 1, \
			REDIR_OUT, status));
}