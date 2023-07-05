/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_lst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 11:45:26 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/04 15:31:02 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	ft_update_list(t_ms *ms, char *name, char *new_info)
{
    t_lst *lst;

    lst = ms->ms_env;
   while(lst)
   {
        if(ft_strcmp(lst->name, name) == 0)
        {
            lst->full_info = ft_strjoin(name, ft_strjoin("=", new_info));
            lst->info = new_info;
            return ;
        }
        lst = lst->next;
   }
}