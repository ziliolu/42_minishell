/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 11:45:26 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/06/27 17:12:39 by lpicoli-         ###   ########.fr       */
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
            list->info = new_info;
            //ft_print_env(ms);
            return ;
        }
        if(ft_strcmp(list->name, "OLDPDW") == 0)
        {
            list->info = "teste";
            //ft_print_env(ms);
            return ;
        }
        list = list->next;
   }
}