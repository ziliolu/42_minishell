/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 17:20:33 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/04 15:26:30 by lpicoli-         ###   ########.fr       */
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

void ft_export(t_ms *ms, t_command *cmd)
{
    if(ft_strchr_vars(cmd->args[1], '='))
    {
        
    }
}

/**

 * se formato 1 (nome) 
    a) existe na lista de vars -> buscar na var_list e adicionar nó no env
    b) nao existe na vars list -> nao faz nada
 * se formato 2 (nome=maria)
 *  a) existe ja em env -> update_env
 *  b) nao existe no env -> adicionar nó no env diretamente 
*/