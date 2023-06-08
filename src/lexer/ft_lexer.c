/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:44:30 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/06/08 12:44:04 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void ft_lexer(t_ms *ms, char *str)
{
    enum e_status status;
    t_elem **elem_head;
    int i;
    
    (void) ms;
    status = GENERAL; //default
    elem_head = (t_elem **)malloc(sizeof(t_elem *));
    i = 0;

    while(str[i])
    {
        if(str[i] == WHITE_SPACE)
            ft_add_new_elem(elem_head, ft_new_elem(str + i, 1, WHITE_SPACE, status));
        else if(str[i] == SINGLE_QUOTE)
            ft_add_new_elem(elem_head, ft_new_elem(str + i, 1, SINGLE_QUOTE, status));
        else if(str[i] == DOUBLE_QUOTE)
            ft_add_new_elem(elem_head, ft_new_elem(str + i, 1, DOUBLE_QUOTE, status));
        else if(str[i] == PIPE_LINE)
            ft_add_new_elem(elem_head, ft_new_elem(str + i, 1, PIPE_LINE, status));
        else if(str[i] == REDIR_IN)
            ft_add_new_elem(elem_head, ft_new_elem(str + i, 1, REDIR_IN, status));
        else if(str[i] == REDIR_OUT)
            ft_add_new_elem(elem_head, ft_new_elem(str + i, 1, REDIR_OUT, status));
        else
        {
            if(str[i] == '$' && ft_is_normal_character(str[i +1]))
                ft_add_new_elem(elem_head, ft_new_elem(str + i, ft_count_char(str + i), ENV, status));
            else
                ft_add_new_elem(elem_head, ft_new_elem(str + i, ft_count_char(str + i), WORD, status));
            i = i + ft_count_char(str + i) - 1;
        }
        if(!str[i + 1])
            break;
        i++;
        //i++;
    }
    ft_print_tokens(*elem_head);
}

int ft_count_char(char *str)
{ 
    int i;
    i = 0;
    while(str[i] != WHITE_SPACE && str[i] != SINGLE_QUOTE && str[i] != DOUBLE_QUOTE && str[i] != '\0')
        i++;
    return (i);
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