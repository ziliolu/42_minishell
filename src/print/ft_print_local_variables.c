/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_local_variables.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:29:10 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/04 14:36:35 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void ft_print_local_variables(t_var **head)
{
    t_var *list;
    int i;

    list = *head;
    i = 0;
    while(list)
    {
        printf("[%d] %s = %s\n", i, list->name, list->info);
        i++;
        list = list->next;
    }
}