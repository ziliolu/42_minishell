/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 13:05:23 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/12 18:41:37 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void ft_exit(t_ms *ms)
{
    ft_printf("exit\n");
    //free(tmp_prompt);
    ft_free_env(ms);
    ft_free_array(ms->paths);
    exit(ft_atoi(ms->cmds[0].args[1]));
}