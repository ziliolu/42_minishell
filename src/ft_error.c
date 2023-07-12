/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 10:33:52 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/12 14:44:35 by lpicoli-         ###   ########.fr       */
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

bool ft_error_var_start(t_ms *ms, char *msg, char *str)
{
    (void)ms;
    if(str)
        ft_printf("minishell: %s: %s\n", str, msg);
    return (false);
}