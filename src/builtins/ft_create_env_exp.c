/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_env_exp.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 14:47:25 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/08/01 01:09:50 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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

void	ft_create_exp(t_ms *ms, char **env)
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
	ms->export_list = *env_head;
	free (env_head);
}
