/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 13:05:23 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/12 13:06:05 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void ft_exit(t_ms *ms)
{
    ft_printf("exit\n");
    //free(tmp_prompt);
    ft_free_env(ms);
    ft_free_array(ms->paths);
    exit(0);
}