/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:20:30 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/12 11:15:26 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void ft_unset(t_ms *ms)
{
    if(!ms->cmds->args[1])
    {
        ft_error(ms, "unset: `': not a valid identifier", NULL);
        return ;
    }
    if(!ft_strchr_vars(ms->cmds->args[1], '='))
            ft_remove_node_list(&ms->ms_env, ms->cmds->args[1]);
}