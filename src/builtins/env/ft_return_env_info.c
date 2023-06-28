/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_return_env_info.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 13:31:51 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/06/28 13:32:22 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char *ft_return_env_info(t_ms *ms, char *name)
{
    t_env *list;

    list = ms->ms_env; 
    while(list)
    {
        if(ft_strcmp(list->name, name) == 0)
            return (list->info);
        list = list->next;
    }
    return (NULL);
}