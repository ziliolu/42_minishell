/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_quote_valid.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 00:12:03 by ialves-m          #+#    #+#             */
/*   Updated: 2023/07/21 01:21:21 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

bool ft_is_quote_valid(char *read_content)
{
	int i;
	int s_quote;
	int d_quote;

	i = 0;
	s_quote = 0;
	d_quote = 0;
	while(read_content[i]) //echo "'"hello'"
	{
		if(read_content[i] == SINGLE_QUOTE && d_quote == 0)
		{
			if(s_quote == 0)
				s_quote = 1;
			else
				s_quote = 0;
		}
		else if(read_content[i] == DOUBLE_QUOTE && s_quote == 0)
		{
			if(d_quote == 0)
				d_quote = 1;
			else
				d_quote = 0;
		}
		i++;
	}
	if(s_quote == 1 || d_quote == 1)
    {
        printf("> minishell: unexpected EOF while looking for matching `%c'\n", ft_choose_quotes(s_quote, d_quote));
        printf("minishell: syntax error: unexpected end of file\n");
	    return (false);
    }
	return(true);
}
