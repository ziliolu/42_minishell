/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_quote_valid.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 00:12:03 by ialves-m          #+#    #+#             */
/*   Updated: 2023/08/12 16:44:26 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

bool	ft_is_quote_valid(char *read_content)
{
	t_val_quote	q;

	q.i = -1;
	q.s_quote = 0;
	q.d_quote = 0;
	while (read_content[++q.i])
	{
		if (read_content[q.i] == SINGLE_QUOTE && q.d_quote == 0)
		{
			if (q.s_quote == 0)
				q.s_quote = 1;
			else
				q.s_quote = 0;
		}
		else if (read_content[q.i] == DOUBLE_QUOTE && q.s_quote == 0)
		{
			if (q.d_quote == 0)
				q.d_quote = 1;
			else
				q.d_quote = 0;
		}
	}
	if (!ft_is_quote_valid_msg(read_content, q.s_quote, q.d_quote))
		return (false);
	return (true);
}
