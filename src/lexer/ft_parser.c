/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 17:56:37 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/06/12 18:50:16 by ialves-m         ###   ########.fr       */
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
	char *str;

	i = 0;
	counter = ft_count_tokens(list);
	ms->n_pipes = ft_count_pipes(list);

	ft_initialize_pipes(ms, ms->n_pipes);
	ms->cmds = malloc(sizeof(t_command) * (ms->n_pipes + 1));
	str = ft_calloc(ms->read_size, sizeof(char));
	while( i <= ms->n_pipes)
	{
		//lembrar de modificar numero da alocacao de memoria 
		ms->cmds[i].args = ft_calloc(counter, sizeof(char *));
		if(!ms->cmds[i].args)
			return ; 
		i++;
	}
	i = 0;
	while (list != NULL && i <= ms->n_pipes)
	{
		j = 0;
		while (list != NULL && list->type != PIPE_LINE)
		{
			str = ft_calloc(ms->read_size, sizeof(char));
			//falta a verificacao se ha plicas e aspas antes e depois para nao expandir
			if(list->type == ENV)
				ms->cmds[i].args[j] = ft_expand(*ms_env, list->data);
			// else
			// 	ms->cmds[i].args[j] = ft_strdup(list->data);
			else if(list->type == SINGLE_QUOTE)
			{
				if(list->status == IN_DQUOTE)
					str = ft_strjoin(str, list->data); //"

				list = list->next;//hello
				while(list->type != SINGLE_QUOTE)
				{
					str = ft_strjoin(str, list->data); //hello //ola  // echo '"hello"'
					list = list->next;
				}
				if(list->status == IN_DQUOTE)
					str = ft_strjoin(str, list->data);
				ms->cmds[i].args[j] = str;
			}
			else if(list->type == DOUBLE_QUOTE)
			{
				if(list->status == IN_SQUOTE)
					str = ft_strjoin(str, list->data); //"

				list = list->next;//hello
				while(list->type != DOUBLE_QUOTE)
				{
					str = ft_strjoin(str, list->data); //hello //ola  // echo '"hello"'
					list = list->next;
				}
				if(list->status == IN_SQUOTE)
					str = ft_strjoin(str, list->data);
				ms->cmds[i].args[j] = str;
			}
			else
				ms->cmds[i].args[j] = ft_strdup(list->data);
			list = list->next;
			j++;
		}
		//necessaria a criacao do pipeline aqui
		if(list != NULL)
			list = list->next;
		ms->cmds[i].args[j] = NULL;
		i++;
	}
	ft_print_command_nodes(ms, ms->n_pipes);
}

void ft_print_command_nodes(t_ms *ms, int n_pipes)
{
	int i;
	int j;
	i = 0;
	j = 0;
	printf("\n------ PRINTANDO COMANDOS----------\n");
	while(i <= n_pipes)
	{
		j = 0;
		printf("\nCOMMAND %i\n", i);
		while(ms->cmds[i].args[j] != NULL)
		{
			printf("%s\n", ms->cmds[i].args[j]);
			j++;
		}
		i++;
	}
	printf("--------------------------------------\n\n");
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


