/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ms.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 12:37:27 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/06/05 16:37:55 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void ft_init_ms(t_ms *ms, char **system_env, char *read_content)
{
    int i;

    i = -1;
    ms->paths = ft_split(ft_getenv("PATH"), ':');
    while(ms->paths[++i])
    {
        ms->paths[i] = ft_strjoin(ms->paths[i], "/");
    }
    //ms->input = ft_strtrim(read_content, " ");
    ms->ms_argv = ft_split(read_content, ' ');
    ms->system_env = system_env;
}