/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ms.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 12:37:27 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/21 16:33:46 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_init_ms(t_ms *ms, char **system_env)
{
    // int		i;
	// char	*tmp;

    // i = 0;
	ms->paths = ft_split(ft_getenv(ms, "PATH"), ':');
	// tmp = malloc(sizeof(char));
	// while(ms->paths[i])
    // {
	// 	ft_strlcpy(tmp, ms->paths[i], ft_strlen(ms->paths[i]));
	// 	free (ms->paths[i]);
	// 	ms->paths[i] = ft_strjoin(tmp, "/");
	// 	i++;
    // }
	// free (tmp);
    ms->system_env = system_env;
}
