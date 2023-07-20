/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_node_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:27:55 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/20 16:39:17 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void ft_remove_node_list(t_lst **head, char *str)
{
    t_lst *tmp;
    t_lst *list;
    char *name;

    list = *head;
    
    if(!str)
        return ; 

    //nome=cuiza
    name = ft_get_list_name(str);
    if(list->next == NULL && ft_strcmp(list->name, name) == 0)
    {
        free(list);
        *head = NULL;
    }
    else if(list->next->next == NULL && ft_strcmp(list->name, name) == 0)
    {
        tmp = list;
        *head = tmp->next;
        free(tmp);
    }
    while(head && list->next)
    {
        if(ft_strcmp(list->next->name, name) == 0)
        {
            tmp = list->next;
            list->next = tmp->next;
            ft_free_node(tmp);
            ft_free(name);
            return ;
        }
        list = list->next;
    }
    ft_free(name);
}