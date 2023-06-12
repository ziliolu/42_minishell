/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 17:56:37 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/06/12 12:59:38 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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
	int			counter;
	int n_pipes;

	i = 0;
	counter = ft_count_tokens(list);
	n_pipes = ft_count_pipes(list);

	ft_initialize_pipes(ms, ft_count_pipes(list));
	ms->cmds = malloc(sizeof(t_command) * (n_pipes + 1));
	
	while( i <= n_pipes)
	{
		//lembrar de modificar numero da alocacao de memoria 
		ms->cmds[i].args = malloc(sizeof(char *) * 10);
		i++;
	}
	i = 0;
	while (list != NULL && i <= n_pipes)
	{
		j = 0;
		while (list != NULL && list->type != PIPE_LINE)
		{
			//falta a verificacao se ha plicas e aspas antes e depois para nao expandir
			if(list->type == ENV)
				ms->cmds[i].args[j] = ft_expand(*ms_env, list->data);
			else
				ms->cmds[i].args[j] = ft_strdup(list->data);
			list = list->next;
			j++;
		}
		//necessaria a criacao do pipeline aqui
		if(list != NULL)
			list = list->next;
		i++;
	}
	ft_print_command_nodes(ms, n_pipes);
}

void ft_print_command_nodes(t_ms *ms, int n_pipes)
{
	int i;
	int j;
	i = 0;
	j = 0;
	printf("\nPRINTANDO COMANDOS\n");
	while(i <= n_pipes)
	{
		j = 0;
		printf("\nCOMMAND %i\n", i);
		while(ms->cmds[i].args[j])
		{
			printf("%s\n", ms->cmds[i].args[j]);
			j++;
		}
		i++;
	}
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


