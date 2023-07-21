/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_counters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:02:56 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/21 16:37:44 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void ft_free_counters(t_counters *c)
{
    if(c->str)
        free(c->str);
    // if(c->tmp_str)
    //     free(c->tmp_str);
    if(c->tmp_arg)
        free(c->tmp_arg);
    // if(c->list)
    //     free(c->list);
    free(c);
}