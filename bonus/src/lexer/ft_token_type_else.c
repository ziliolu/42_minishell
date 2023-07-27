/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_type_else.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:50:57 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/21 21:58:11 by ialves-m         ###   ########.fr       */
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
	else
		return (NULL);
}
