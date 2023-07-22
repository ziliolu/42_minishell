/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:36:32 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/23 00:29:37 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	ft_free(char *str)
{
	if (str)
		free(str);
}

void	ft_free_memory(t_ms *ms)
{
	ft_free_array(ms->paths);
	ft_free_array(ms->ms_env_array);
	ft_free_env(ms);
	if (ms->ms_argv)
		ft_free_array(ms->ms_argv);
	if (ms->cmds)
		ft_free_cmds(ms);
	if (ms->count_args)
		free (ms->count_args);
}

void	ft_free_cmds(t_ms *ms)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	if (ms->cmds)
	{
		while (ms->cmds[i].type)
		{
			if (ms->cmds[i].redirs)
			{
				k = 0;
				while (ms->cmds[i].redirs[k].arg)
					free(ms->cmds[i].redirs[k++].arg);
				free (ms->cmds[i].redirs);
			}
			while (ms->cmds[i].args[j])
			{
				if (ms->cmds[i].type != PIPE_LINE)
					if (ms->cmds[i].args[j]
						&& ft_strcmp(ms->cmds[i].args[j], "") != 0)
						free (ms->cmds[i].args[j]);
				j++;
			}
			j = 0;
			if (ms->cmds[i].args)
				free (ms->cmds[i].args);
			i++;
		}
		if (ms->cmds)
			free (ms->cmds);
	}
}

void	ft_free_env(t_ms *ms)
{
	t_lst	*list;

	list = NULL;
	list = ms->ms_env;
	while (ms->ms_env)
	{
		if (ms->ms_env)
		{
			list = ms->ms_env->next;
			free (ms->ms_env->name);
			free (ms->ms_env->info);
			free (ms->ms_env->full_info);
			free (ms->ms_env);
		}
		ms->ms_env = list;
	}
	if (list)
		free (list);
}

void	ft_free_elem_list(t_elem *head)
{
	t_elem	*list;

	list = NULL;
	list = head;
	while (head)
	{
		if (head)
		{
			list = head->next;
			free (head->data);
			free (head);
		}
		head = list;
	}
	if (list)
		free (list);
}

void	ft_free_array(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
	{
		if (array[i])
			free (array[i++]);
	}
	if (array)
		free (array);
}

void	ft_free_node(t_lst *node)
{
	free(node->full_info);
	free(node->info);
	free(node->name);
	free(node);
}
