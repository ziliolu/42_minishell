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

void	ft_update_list(t_lst *list, char *name, char *new_info)
{
   while(list)
   {
        if(ft_strcmp(list->name, name) == 0)
        {
            list->full_info = ft_strjoin(name, ft_strjoin("=", new_info));
            list->info = new_info;
            return ;
        }
        list = list->next;
   }
}