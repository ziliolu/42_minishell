/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_arg_redir.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 10:58:57 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/22 21:18:15 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool	ft_is_arg_redir(char *arg)
{
	if (arg)
	{
		if (ft_strcmp(arg, ">") == 0 || ft_strcmp(arg, ">>") == 0
			|| ft_strcmp(arg, "<") == 0 || ft_strcmp(arg, "<<") == 0)
			return (true);
	}
	return (false);
}
