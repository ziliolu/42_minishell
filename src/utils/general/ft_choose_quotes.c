/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_choose_quotes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 00:11:01 by ialves-m          #+#    #+#             */
/*   Updated: 2023/07/21 11:58:34 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char ft_choose_quotes(int s_quote, int d_quote)
{
    if(s_quote % 2 != 0)
        return ('\'');
    else if(d_quote % 2 != 0)
        return ('\"');
    return (1);
}
