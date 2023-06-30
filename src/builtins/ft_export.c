/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 17:20:33 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/06/30 17:56:55 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/**
 * EXPORT - INFOS IMPORTANTES 
 * 
 * Quando você define uma variável sem usar o comando export, 
 * ela não aparecerá na saída do comando env. O comando env exibe 
 * apenas as variáveis de ambiente que foram explicitamente exportadas.

    Apenas as variáveis que foram exportadas usando o comando export 
    serão visíveis no ambiente e serão listadas pelo comando env.
*/

void ft_add_local_variable(t_var **head, char *name, char *info)
{
    t_var *new_node;
    t_var *last_node;
    
    new_node = ft_calloc(1, sizeof(t_var));
    new_node->name = ft_strdup(name);
    new_node->info = ft_strdup(info);
    new_node->next = NULL;

    //if the list is empty, new node becomes the first
    if(*head == NULL)
    {
        *head = new_node;
        printf("var name->>> %s\n", new_node->name);
        printf("var info->>> %s\n", new_node->info);
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

void ft_export()
{

}