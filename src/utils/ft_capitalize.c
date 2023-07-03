/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_capitalize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 19:48:11 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/03 20:26:28 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char *ft_capitalize(char *str)
{
    int i;
    char *new_str;

    i = 0;
    printf("%s\n", str);
    new_str = ft_calloc(ft_strlen(str), sizeof(char));
    printf("%d\n", (int)ft_strlen(str));
    while(i < (int)ft_strlen(str))
    {
        new_str[i] = ft_toupper(str[i]);
        i++;
    }
    printf("%s\n", new_str);
    return (new_str);
}