/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 10:58:57 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/22 21:17:55 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool	ft_is_redir(enum e_token type)
{
	if (type == REDIR_IN || type == REDIR_OUT
		|| type == D_REDIR_OUT || type == HERE_DOC)
		return (true);
	return (false);
}
