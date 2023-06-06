/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:44:30 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/06/06 17:01:55 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"


void ft_parser(t_ms *ms, char *read_content)
{
    enum e_token type;
    t_elem **elem_head;
    //t_elem *list;
    int i;

    (void) read_content;
    (void) ms;
    type = WORD;
    elem_head = (t_elem **)malloc(sizeof(t_elem *));
    i = 0;

    while(read_content[i])
    {
        if(read_content[i] == ' ')
            ft_add_new_elem(elem_head, )
        else if()    
    }
    
    printf("%d\n", type);
}


/* void ft_env(char **env)
{
	t_env	**env_head;
	t_env	*list;
	int		i;

	//Inicialização do Ponteiro para a lista de Nodes
	env_head = (t_env **)malloc(sizeof(t_env *));

	//Criação do Primeiro Node
	i = 0;
	list = ft_new_node(env[i++]);
	*env_head = list;
	
	//Criação dos Seguintes Nodes
	while (env[i])
		ft_add_node(env_head, env[i++]);

	//Impressão da lista com todos os elementos do "env"
	//ft_print_list(*env_head);
	ms_env = env_head;
} */