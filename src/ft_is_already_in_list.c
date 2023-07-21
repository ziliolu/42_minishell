/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_already_in_list.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 00:05:32 by ialves-m          #+#    #+#             */
/*   Updated: 2023/07/21 00:06:51 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

bool ft_is_already_in_list(char *name, t_lst *list)
{
    while(list)
    {
        if(ft_strcmp(list->name, name) == 0)
            return (true);
        list = list->next;
    }
    return (false);
}
