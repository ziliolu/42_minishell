/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 14:47:25 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/06/02 14:45:02 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_env(char **env)
{
	t_env	**env_head;
	t_env	*list;
	int		i;

	//Apenas um teste das funções que separam os argumentos do "env"
	// i = -1;
	// while (env[++i])
	// 	printf("NAME: %s\nINFO: %s\nTOTAL INFO: %s\n\n", get_env_name(env[i]), get_env_info(env[i]), env[i]);


	//Inicialização do Ponteiro para a lista de Nodes
	env_head = (t_env **)malloc(sizeof(t_env *));

	//Criação do Primeiro Node
	i = 0;
	list = new_node(env[i++]);
	*env_head = list;
	
	//Criação dos Seguintes Nodes
	while (env[i])
		add_node(env_head, env[i++]);

	//Impressão da lista com todos os elementos do "env"
	print_list(*env_head);
}

t_env	*new_node(char *str)
{
	t_env	*var;

	var = (t_env *)malloc(sizeof(t_env));
	if (var)
	{
		var->name = get_env_name(str);
		var->info = get_env_info(str);
		var->full_info = str;
		var->next = NULL;
		return (var);
	}
	free (var);
	return (NULL);
}

void	add_node(t_env **header, char *str)
{
	t_env	*new;
	t_env	*last;

	new = new_node(str);
	last = find_last(*header);
	last->next = new;
}

t_env	*find_last(t_env *list)
{
	while (list->next != NULL)
		list = list->next;
	return (list);
}

char	*get_env_name(char *set)
{
	int 	i;
	
	i = 0;
	while (set[i] != '=')
		i++;
	return (ft_substr(set, 0, i));
}

char	*get_env_info(char *set)
{
	int 	i;
	
	i = 0;
	while (set[i] != '=')
		i++;
	return (ft_substr(set, i+1, ft_strlen(set)));
}

void	print_list(t_env *list)
{
	while (list != NULL)
	{
		printf("Name: %s\nInfo: %s\nFull Info: %s\n", list->name, list->info, list->full_info);
		list = list->next;
		printf("\n");
	}
}