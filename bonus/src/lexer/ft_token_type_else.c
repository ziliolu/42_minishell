/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_type_else.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:50:57 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/28 14:33:21 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_token_type_else(enum e_token type)
{
	if (type == REDIR_IN)
		return ("redir_in");
	else if (type == REDIR_OUT)
		return ("redir_out");
	else if (type == D_REDIR_OUT)
		return ("d_redir_out");
	else if (type == HERE_DOC)
		return ("here_doc");
	else if (type == CMD)
		return ("command");
	else if(type == AND)
		return ("and");
	else if(type == OR)
		return ("or");
	else if(type == P_CLOSE)
		return (")");
	else if(type == P_OPEN)
		return (")");
	else
		return (NULL);
}
