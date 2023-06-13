/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 10:58:57 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/06/13 10:59:07 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool ft_is_redir(enum e_token type)
{
	if(type == REDIR_IN || type == REDIR_OUT || type == D_REDIR_OUT || type == HERE_DOC)
		return (true);
	return (false);
}