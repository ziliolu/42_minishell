/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_there_space.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 16:54:08 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/14 16:54:18 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool ft_is_there_space(char *str)
{
    int i = 0;

    while (str[i] != '\0')
    {
        if (str[i] == ' ' || str[i] == '\t')
            return true;
        i++;
    }
    return false;
}
