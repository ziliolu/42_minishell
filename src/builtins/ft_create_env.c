/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 14:47:25 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/04 15:51:43 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"


void ft_create_env(t_ms *ms, char **env)
{
	t_lst	**env_head;
	t_lst	*list;
	int		i;

	//Inicialização do Ponteiro para a lista de Nodes
	env_head = (t_lst **)ft_calloc(1, sizeof(t_lst *));

	//Criação do Primeiro Node
	i = 0;
	list = ft_new_node(env[i++]);
	*env_head = list;
	
	//Criação dos Seguintes Nodes
	while (env[i])
		ft_add_node(env_head, env[i++]);

	//Impressão da lista com todos os elementos do "env"
	//ft_print_list(*env_head);
	ms->ms_env = *env_head;
	free (env_head);
}
