/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_arg_valid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 17:52:43 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/06/05 18:13:32 by lpicoli-         ###   ########.fr       */
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
	while(read_content[i])
	{
		if(read_content[i] == '\'')
			s_quote++;
		else if(read_content[i] == '\"')
			d_quote++;
		i++;
	}
	if(ft_choose_quotes(s_quote, d_quote) != 1)
    {
        printf("> minishell: unexpected EOF while looking for matching `%c'\n", ft_choose_quotes(s_quote, d_quote));
        printf("minishell: syntax error: unexpected end of file\n");
	    return (false);
    }
	return(true);
}

char ft_choose_quotes(int s_quote, int d_quote)
{
    if(s_quote % 2 != 0)
        return ('\'');
    else if(d_quote % 2 != 0)
        return ('\"');
    return (1);
}
bool ft_is_arg_valid(t_ms *ms, char *read_content)
{
    (void)ms;
	if(!ft_is_quote_valid(read_content))
		return (false);
    return (true);
}