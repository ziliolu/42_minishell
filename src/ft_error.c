/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 10:33:52 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/14 16:01:17 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include <stdbool.h>

bool ft_error(t_ms *ms, char *msg, char *str)
{
    ft_reset_fd_in_out(ms);
    if(!str)
        ft_printf("minishell: %s\n", msg);
    else
        ft_printf("minishell: %s: %s\n", msg, str);
    return(false);
}

bool ft_error_var_start(char *msg, char *str, int err_number)
{
    if(str)
    {
        ft_printf("minishell: %s: %s\n", str, msg);
        g_exit_status = err_number;
    }
    return (false);
}