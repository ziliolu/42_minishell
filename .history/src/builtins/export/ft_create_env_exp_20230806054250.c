/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_env_exp.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 16:18:53 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/08/06 05:42:50 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

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

t_export	*ft_init_export_variables(void)
{
	t_export	*exp;

	exp = ft_calloc(1, sizeof(t_export));
	exp->upper_case = 'A';
	exp->lower_case = 'a';
	exp->underscore = '_';
	return (exp);
}

void	ft_create_exp(t_ms *ms, char **env)
{
	t_lst		**env_head;
	t_lst		*list;
	t_export	*exp;

	exp = ft_init_export_variables();
	env_head = (t_lst **)ft_calloc(1, sizeof(t_lst *));
	list = ft_new_node(env[0]);
	*env_head = list;
	while (exp->lower_case <= 'z')
	{
		ms->i = 1;
		while (env[ms->i])
		{
			if (env[ms->i][0] == exp->upper_case
				|| env[ms->i][0] == exp->lower_case
				|| env[ms->i][0] == exp->underscore)
				ft_add_node(env_head, env[ms->i]);
			ms->i++;
		}
		exp->upper_case++;
		exp->lower_case++;
		exp->underscore = 96;
	}
	ms->export_list = *env_head;
	ft_creat_exp_free(exp, env_head);
}

void	ft_creat_exp_free(t_export *exp, t_lst **env_head)
{
	free (env_head);
	free (exp);
}
