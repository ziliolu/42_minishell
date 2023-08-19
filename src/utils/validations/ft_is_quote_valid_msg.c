/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_quote_valid_msg.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 00:12:03 by ialves-m          #+#    #+#             */
/*   Updated: 2023/08/12 16:44:18 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

bool	ft_is_quote_valid_msg(char *read_content, int s_quote, int d_quote)
{
	(void) read_content;
	if (s_quote == 1 || d_quote == 1)
	{
		printf("> minishell: unexpected EOF while looking for matching `%c'\n", \
			ft_choose_quotes(s_quote, d_quote));
		printf("minishell: syntax error: unexpected end of file\n");
		g_exit_status = 2;
		free(read_content);
		return (false);
	}
	return (true);
}
