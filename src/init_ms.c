/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ms.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 12:37:27 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/06/29 12:19:31 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_init_ms(t_ms *ms, char **system_env)
{
    int		i;

    i = 0;
	ms->paths = ft_split(ft_getenv(ms, "PATH"), ':');
	while(ms->paths[i])
    {
		ms->paths[i] = ft_strjoin(ms->paths[i], "/");
		i++;
    }
    ms->system_env = system_env;
}
