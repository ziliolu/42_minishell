/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_env_exp.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 14:47:25 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/08/02 12:36:02 by lpicoli-         ###   ########.fr       */
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
	char	upper_letter;
	char	lower_letter;
	char underscore;
	int		i;

	upper_letter = 'A';
	lower_letter = 'a';
	underscore = '_';
	env_head = (t_lst **)ft_calloc(1, sizeof(t_lst *));
	list = ft_new_node(env[0]);
	*env_head = list;

	while(lower_letter <= 'z')
	{
		i = 1;
		while (env[i])
		{
			if(env[i][0] == upper_letter || env[i][0] == lower_letter || env[i][0] == underscore)	
				ft_add_node(env_head, env[i]);
			i++;
		}
		upper_letter++;
		lower_letter++;
		underscore = 96;
	}
	ms->export_list = *env_head;
	free (env_head);
}
