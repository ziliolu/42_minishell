/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer_if_str_redir_in.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:50:18 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/25 11:35:15 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_lexer_if_str_redir_in(t_lexer *x, t_elem **elem_head, \
	char *str, enum e_status *status)
{
	if (str[x->i + 1] == REDIR_IN)
	{
		ft_add_new_elem(elem_head, ft_new_elem(str + x->i, 2, \
			HERE_DOC, status));
		x->i++;
	}
	else
		ft_add_new_elem(elem_head, ft_new_elem(str + x->i, 1, \
			REDIR_IN, status));
}
