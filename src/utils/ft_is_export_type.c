/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_export_type.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 16:22:22 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/14 16:55:14 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/minishell.h"

bool ft_is_export_type(char *str)
{
    int i = 0;

    while (str[i] != '\0')
    {
        if (((str[i] == ' ' || str[i] == '\t') && (str[i - 1] == '=')) || (ft_strchr_vars(str, '=') && !ft_is_there_space(str)))
            return true;
        i++;
    }
    return false;
}
