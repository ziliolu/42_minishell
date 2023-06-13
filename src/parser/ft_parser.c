/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 17:56:37 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/06/13 12:19:06 by lpicoli-         ###   ########.fr       */
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
	int			k;
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
		k = 0;
		ms->cmds[i].redirs = malloc(sizeof(t_redirect) * counter);
		while(k < counter)
		{
			ms->cmds[i].redirs[k].arg = NULL;
			k++;
		}
		k = 0;
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
					str = ft_strjoin(str, list->data); 

				list = list->next;
				while(list->type != SINGLE_QUOTE)
				{
					str = ft_strjoin(str, list->data); 
					list = list->next;
				}
				if(list->status == IN_DQUOTE)
					str = ft_strjoin(str, list->data);
				ms->cmds[i].args[j] = str;
			}
			else if(list->type == DOUBLE_QUOTE)
			{
				if(list->status == IN_SQUOTE)
					str = ft_strjoin(str, list->data); 

				list = list->next;
				while(list->type != DOUBLE_QUOTE)
				{
					str = ft_strjoin(str, list->data);
					list = list->next;
				}
				if(list->status == IN_SQUOTE)
					str = ft_strjoin(str, list->data);
				ms->cmds[i].args[j] = str;
			}
			else if(ft_is_redir(list->type))
			{
				ms->cmds[i].redirs[k].type = list->type;
				if (!list->next)
				{
					printf("bash: syntax error near unexpected token `newline'\n");
					return ;
				}
				ms->cmds[i].redirs[k].arg = ft_strdup(list->next->data);
				k++;
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


