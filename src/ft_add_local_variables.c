/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_local_variables.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:28:23 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/06 13:41:04 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// nome=maria (sem export)
void ft_add_node_to_list(t_ms *ms, t_lst **head, char *str)
{
    //t_lst *new_node;
    //t_lst *last_node;
    (void)ms;

    char *name;

    name = ft_get_list_name(str);
    
    if(ft_is_already_in_list(name, *head))
    {
        ft_update_list(*head, name, ft_get_list_info(str));
        return ; 
    }
    else if(ft_is_already_in_list(name, ms->ms_env))
    {
        ft_update_list(ms->ms_env, name, ft_get_list_info(str));
        return ; 
    }
    ft_add_node(head, str);
    
    // new_node = ft_calloc(1, sizeof(t_list));
    // new_node->name = name;
    // new_node->info = info;
    // new_node->next = NULL;

    // //if the list is empty, new node becomes the first
    // if(*head == NULL)
    // {
    //     printf("init lista de args!\n");
    //     *head = new_node;
    // }
    // else
    // {
    //     printf("entrou no else de add_new_node");
    //     ft_find_last(*head)->next = new_node;
    // }
    //find last node of the list + add new node in the end of the list
    

    //last_node->next = new_node;
}

// void ft_update_list_info(t_lst *list, char *name, char *info)
// {

//     //char *name; 
//     //char *info;

//     //name = ft_get_list_name(str);
//    // printf("%s\n", name);
// 	//info = ft_get_list_info(str);
//     //printf("%s\n", info);

    
//     while(list)
//     {
//         if(ft_strcmp(list->name, name) == 0)
//         {
//             list->info = info;
//             list->full_info = ft_return_list_full_info(list, name);
//             return ; 
//         }
//         list = list->next;
//     }
// }

// void	ft_update_list(t_ms *ms, char *name, char *new_info)
// {
//     t_lst *lst;

//     lst = ms->ms_env;
//    while(lst)
//    {
//         if(ft_strcmp(lst->name, name) == 0)
//         {
//             lst->full_info = ft_strjoin(name, ft_strjoin("=", new_info));
//             lst->info = new_info;
//             return ;
//         }
//         lst = lst->next;
//    }
// }

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