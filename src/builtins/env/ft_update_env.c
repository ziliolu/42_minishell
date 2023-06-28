/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 11:45:26 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/06/28 10:34:59 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	ft_update_env(t_ms *ms, char *name, char *new_info)
{
    t_env *list;

    list = ms->ms_env;
   while(list)
   {
        if(ft_strcmp(list->name, name) == 0)
        {
            list->full_info = ft_strjoin(name, ft_strjoin("=", new_info));
            return ;
        }
        list = list->next;
   }
}