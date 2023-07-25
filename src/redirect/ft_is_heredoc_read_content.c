/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_heredoc_read_content.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 10:01:08 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/23 00:17:56 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_is_heredoc_read_content(t_command *cmd, t_heredoc *h)
{
	while (ft_strcmp(h->read_content, h->eof) != 0)
	{
		h->read_content = readline(h->prompt);
		if (!h->read_content)
		{
			cmd->err = true;
			printf("\n");
			return (NULL);
		}
		else
		{
			if (ft_strcmp(h->read_content, h->eof) == 0)
				break ;
			h->str = ft_strjoin(h->str, h->read_content);
			h->str = ft_strjoin(h->str, "\n");
		}
	}
	return (h->str);
}
