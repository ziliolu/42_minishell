/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 17:56:37 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/06/12 11:37:06 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"


// para segunda: acho que a maneira mais facil de organizar 
//o array de args dentro das estruturas dos comandos sera durante a montagem da tabela do lexer
// fazendo sempre um ft_strjoin com o anterior
// seguindo algumas regras como: 

// nao adicionar WHITE_SPACES do status GENERAL 
// nao adicionar plicas ou aspas do status GENERAL (verificar casos de status IN_SQUOTE e IN_DQUOTE)
// expandir variaveis do tipo ENV e ja guarda-las da maneira correta (expandida)


int ft_count_pipes(t_elem *list)
{
	int pipes;

	pipes = 0;
	while(list != NULL)
	{
		if(list->type == PIPE_LINE)
			pipes++;
		list = list->next;
	}
	return (pipes);
}

void ft_parser(t_ms *ms, t_elem *list)
{
   	int			i;
	int			j;
	char		*str;
	int			counter;
	int n_pipes;
	//int cmds_before_pipe;

	i = 0;
	counter = ft_count_tokens(list);
	n_pipes = ft_count_pipes(list);

	ft_initialize_pipes(ms, ft_count_pipes(list));
	ms->cmds = malloc(sizeof(t_command) * (n_pipes + 1));

	while (list != NULL)
	{
		j = 0;
		while (list->type != PIPE_LINE)
		{
			ms->cmds[i].args[j] = ft_strdup(list->data);
			list = list->next;
			j++;
		}
		i++;
	}
	ft_print_command_nodes(ms);
}

// int ft_count_cmds_before_pipe(t_elem *list)
// {
// 	int i;
// 	while(list->data != NULL)
// 	{
// 		while(list->type != PIPE_LINE )
// 	}
// }


void ft_print_command_nodes(t_ms *ms)
{
	int i;
	int j;
	i = 0;
	j = 0;
	printf("\n PRINTANDO COMANDOS\n");
	while(ms->cmds[i].args[j])
	{
		printf("%s\n", ms->cmds[i].args[j]);
		j++;
	}
	i++;
}
bool ft_is_not_redir(enum e_token type)
{
	if(type != REDIR_IN && type != REDIR_OUT && type != HERE_DOC && type != D_REDIR_OUT)
		return (true);
	return (false);
}

void ft_initialize_pipes(t_ms *ms, int nbr_of_pipes)
{
	ms->pipes = malloc(sizeof(t_pipe) * nbr_of_pipes);
}


