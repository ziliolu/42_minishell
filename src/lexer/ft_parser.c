/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 17:56:37 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/06/10 20:03:57 by lpicoli-         ###   ########.fr       */
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
	//t_command	*node;
   	int			i;
	int			j;
	char *str;

	i = 0;
	j = 0;
	ft_initialize_pipes(ms, ft_count_pipes(list));
	ms->cmds = malloc(sizeof(t_command) * (ft_count_pipes(list) + 1));
	while (list != NULL)
	{
		j = 0;
		while (list->type != PIPE_LINE)
		{
			while(!(list->type == WHITE_SPACE && list->status == GENERAL))
			{
				str = ft_strjoin(str, list->data);
				list = list->next;
			}
			ms->cmds[i].args[j] = ft_strdup(str);
			j++;
		}
		i++;
		//list->len, ft_token_status(list->status), ft_token_type(list->type));
		list = list->next;
	}
	ft_print_command_nodes(ms);
}

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