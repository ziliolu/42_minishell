/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_redirs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 18:14:39 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/06/16 18:26:51 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int ft_count_redirs(t_elem *list)
{
	int i;

	i = 0;
	while(list && list->type != PIPE_LINE)
	{
		if(!ft_is_not_redir(list->type))
			i++;
		list = list->next;
	}
	return (i);
}

int ft_count_redirs_cmd(t_command *cmd)
{
	int i;

	i = 0;
	while(cmd->redirs[i].arg != NULL)
	{
		i++;
	}
	return(i);	
}