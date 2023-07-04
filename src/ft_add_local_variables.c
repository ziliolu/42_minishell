/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_local_variables.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:28:23 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/04 15:18:57 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void ft_add_local_variable(t_var **head, char *name, char *info)
{
    t_var *new_node;
    t_var *last_node;
    
    if(ft_is_already_var(name, *head))
    {
        ft_update_vars(*head, name, info);
        return ; 
    }
        
    new_node = ft_calloc(1, sizeof(t_var));
    new_node->name = name;
    new_node->info = info;
    new_node->next = NULL;

    //if the list is empty, new node becomes the first
    if(*head == NULL)
    {
        *head = new_node;
        return ;
    }
    
    //find last node of the list
    last_node = *head;
    while(last_node->next != NULL)
    {
        last_node = last_node->next;
    }
    
    //add new node in the end of the list
    last_node->next = new_node;
}

void ft_update_vars(t_var *list, char *name, char *info)
{
    while(list)
    {
        if(ft_strcmp(list->name, name) == 0)
        {
            list->info = info;
            return ; 
        }
        list = list->next;
    }
}

bool ft_is_already_var(char *name, t_var *list)
{
    while(list)
    {
        if(ft_strcmp(list->name, name) == 0)
            return (true);
        list = list->next;
    }
    return (false);
}