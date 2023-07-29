/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 14:47:25 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/29 00:06:28 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_lst	*ft_create_env(t_ms *ms, char **env)
{
	t_lst	**env_head;
	t_lst	*list;
	int		i;

	(void)ms;
	env_head = (t_lst **)ft_calloc(1, sizeof(t_lst *));
	i = 0;
	list = ft_new_node(env[i++]);
	*env_head = list;
	while (env[i])
		ft_add_node(env_head, env[i++]);
	// ms->ms_env = *env_head;
	return(*env_head);
}

void	ft_create_env(t_ms *ms, char **env)
{
	t_lst	**env_head;
	t_lst	*list;
	int		i;

	env_head = (t_lst **)ft_calloc(1, sizeof(t_lst *));
	i = 0;
	list = ft_new_node(env[i++]);
	*env_head = list;
	while (env[i])
		ft_add_node(env_head, env[i++]);
	ms->ms_env = *env_head;
	free (env_head);
}
