/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 17:20:33 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/06 13:41:26 by lpicoli-         ###   ########.fr       */
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

//export nome=luiza
void ft_export(t_ms *ms, char *str)
{
    char *name;
    char *info;

    name = ft_get_list_name(str);
    info = ft_get_list_info(str);
    if (!str)
        ft_print_export(ms->ms_env);
    else if(ft_is_already_in_list(ft_get_list_name(str), ms->ms_env))
        ft_update_list(ms->ms_env, name, info);
    else if(ft_is_already_in_list(ft_get_list_name(str), *ms->vars))
    {
        if(!ft_strchr_vars(str, '='))
            str = ft_return_list_full_info(*ms->vars, str);
        ft_add_export_node(&ms->ms_env, str);
        ft_remove_node_list(ms->vars, str);
    }
    else
        if(ft_strchr_vars(str, '='))
            ft_add_export_node(&ms->ms_env, str);
}

/**

 * se formato 1 (nome) 
    a) existe na lista de vars -> buscar na var_list e adicionar nó no env
    b) nao existe na vars list -> nao faz nada
 * se formato 2 (nome=maria)
 *  a) existe ja em env -> update_env (nao adicionar em lista local)
 *  b) nao existe no env nem na lista -> adicionar nó na lista local diretamente 
 *  c) existe ja na lista -> update lista 
*/