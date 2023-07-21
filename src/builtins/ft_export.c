/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 17:20:33 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/21 16:31:34 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void ft_export(t_ms *ms, t_command *cmd)
{
    char *name;
    char *info;
    char *str;
    int i;

    i = 1;
	if(!cmd->args[1])
	{
		ft_print_export(ms->ms_env);
		return ;
    }
    while(cmd->args[i])
    { 
        //falta alterar g_exit_status no erro
        if((cmd->args[i + 1] && (cmd->args[i + 1][0] == '=')) || !ft_is_export_type(cmd->args[i]))
        {
            ft_reset_fd_in_out(ms);
            if(!ft_is_export_type(cmd->args[i]))
                ft_printf("minishell: export: `%s': not a valid identifier\n", cmd->args[i]);
            else
                ft_printf("minishell: export: `%s': not a valid identifier\n", cmd->args[i + 1]);
            return ;
        }
        str = ft_strdup(cmd->args[i]);
        name = ft_get_list_name(str);
        info = ft_get_list_info(str);
        if(ft_is_already_in_list(name, ms->ms_env))
            ft_update_list(ms->ms_env, name, info);
        else if(ft_is_already_in_list(name, *ms->vars))
        {
            if(!ft_strchr_vars(str, '='))
                str = ft_return_list_full_info(*ms->vars, str);
            ft_add_export_node(&ms->ms_env, str);
            ft_remove_node_list(ms->vars, str);
        }
        else
        {
            if(ft_strchr_vars(str, '='))
                ft_add_export_node(&ms->ms_env, str);
        }
        ft_free(name);
        ft_free(str);
        ft_free(info);
        i++;
    }
}
