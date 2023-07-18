/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_counters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:02:56 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/18 12:19:45 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void ft_free_counters(t_counters *c)
{
    if(c->str)
        free(c->str);
    if(c->tmp_str)
        free(c->tmp_str);
    if(c->tmp_arg)
        free(c->tmp_arg);    
    free(c);
}