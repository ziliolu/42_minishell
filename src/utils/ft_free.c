/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:36:32 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/04 11:20:40 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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

void ft_free_cmds(t_ms *ms)
{
	int i = 0;
	int j = 0;
	int k;
	if (ms->cmds)
	{
		while (ms->cmds[i].type)
		{
			if (ms->cmds[i].redirs)
			{
				k = 0;
				while(ms->cmds[i].redirs[k].arg)
				{
					free(ms->cmds[i].redirs[k].arg);
					k++;
				}
				free (ms->cmds[i].redirs);
			}
			while(j < ms->count_args[i] + 1)
			{
				if(ms->cmds[i].type != PIPE_LINE)
				{
					if(ms->cmds[i].args[j])
						free (ms->cmds[i].args[j]);
				}
			
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
	t_env *list;
	
	list = NULL;
	list = ms->ms_env;
	while (ms->ms_env)
	{
		if (ms->ms_env)
		{
			list = ms->ms_env->next;
			free (ms->ms_env->name);
			free (ms->ms_env->info);
			//free (ms->ms_env->full_info);
			free (ms->ms_env);
		}
		ms->ms_env = list;
	}
	if (list)
		free (list);
}

void	ft_free_elem_list(t_elem *head)
{
	t_elem *list;
	
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
	while (array[i])
	{
		if (array[i])
		{
			// printf("%s\n", array[i]);
			free (array[i++]);
		}
	}
	if (array)
		free (array);
}
