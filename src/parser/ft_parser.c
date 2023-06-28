/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 17:56:37 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/06/28 17:30:13 by ialves-m         ###   ########.fr       */
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
	char 		*str;
	enum e_token	tmp;

	i = 0;
	counter = ft_count_tokens(list);
	ms->n_pipes = ft_count_pipes(list);

	ft_initialize_pipes(ms, ms->n_pipes);
	ms->cmds = ft_calloc(ms->n_pipes * 2 + 2, sizeof(t_command));
	if (!ms->cmds)
		return ;
	str = ft_calloc(ms->read_size, sizeof(char));
	while(i <= (ms->n_pipes * 2))
	{
		//lembrar de modificar numero da alocacao de memoria 
		ms->cmds[i].args = ft_calloc(ms->count_args[i], sizeof(char *));
		if(!ms->cmds[i].args)
			return ; 
		//printf("Cmd[%d] = %d Args\n", i, ms->count_args[i]);
		i++;
	}
	i = 0;
	while (list != NULL)
	{
		j = 0;
		k = 0;
		//criacao de lista de redirects 
		ms->cmds[i].redirs = ft_calloc(counter, sizeof(t_redirect));
		ms->cmds[i].type = CMD;
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
			if(list->type == ENV && list->status != IN_SQUOTE)
				ms->cmds[i].args[j] = ft_expand(ms->ms_env, list->data);
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
					if(list->type == ENV)
						str = ft_strjoin(str, ft_expand(ms->ms_env, list->data));
					else
						str = ft_strjoin(str, list->data);
					list = list->next;
				}
				if(list->status == IN_SQUOTE)
					str = ft_strjoin(str, list->data);
				if(ft_strcmp(str, "") != 0)
					ms->cmds[i].args[j] = str;
				// else
				// 	j--;
			}
			else if(ft_is_redir(list->type))
			{
				ms->cmds[i].redirs[k].type = list->type;
				if (!list->next)
				{
					printf("bash: syntax error near unexpected token `newline'\n");
					return ;
				}
				list = list->next;
				while (list->type == WHITE_SPACE)
					list = list->next;
				if (list->type == DOUBLE_QUOTE || list->type == SINGLE_QUOTE)
				{
					tmp = list->type;
					list = list->next;
					while (tmp != list->type)
					{
						str = ft_strjoin(str, list->data);
						list = list->next;
					}
					ms->cmds[i].redirs[k].arg = ft_strdup(str);
				}
				else
				{
					
					ms->cmds[i].redirs[k].arg = ft_strdup(list->data);
				}
				j--;
				k++;
			}

			else if (ms->cmds[i].args[j] != NULL)
			{
				ms->cmds[i].args[j] = ft_strjoin(ms->cmds[i].args[j], ft_strdup(list->data));
				if (list->next && (list->next->type == SINGLE_QUOTE || list->next->type == DOUBLE_QUOTE))
					j++;
			}

			else if (list->type != WHITE_SPACE)
			{
				ms->cmds[i].args[j] = ft_strdup(list->data);
				if (list->next && (list->next->type == SINGLE_QUOTE || list->next->type == DOUBLE_QUOTE))
					j++;
			}
			list = list->next;
			if(list && list->type == WHITE_SPACE)
				j++;
			//printf("[%d][%d]Command:%s, Size:%ld\n", i, j, ms->cmds[i].args[j], ft_strlen(ms->cmds[i].args[j]));
			// ls "-"l
		}
		i++;
		j = 0;
		if(list != NULL && list->type == PIPE_LINE)
		{
			ms->cmds[i].args[j] = "|";
			ms->cmds[i].type = PIPE_LINE;
			list = list->next;	
		}
		//ms->cmds[i].args[j] = NULL;
		i++;
	}
	//ft_print_command_nodes(ms, ms->n_pipes);
}


bool ft_is_not_redir(enum e_token type)
{
	if(type != REDIR_IN && type != REDIR_OUT && type != HERE_DOC && type != D_REDIR_OUT)
		return (true);
	return (false);
}

void ft_initialize_pipes(t_ms *ms, int nbr_of_pipes)
{
	ms->pipes = ft_calloc(nbr_of_pipes, sizeof(t_pipe));
}
