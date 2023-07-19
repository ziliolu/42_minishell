/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 14:22:46 by ialves-m          #+#    #+#             */
/*   Updated: 2023/07/19 16:12:40 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_is_redir_double_quote(t_ms *ms, t_counters *p)
{
	(void) ms;
	if (p->list->status == IN_SQUOTE)
		p->str = ft_strjoin(p->tmp_str, p->list->data);
	p->list = p->list->next;
	while (p->list->type != DOUBLE_QUOTE)
	{
		if (p->list->type == ENV)
		{
			p->str = ft_strjoin_wo_leaks(p->tmp_str,
					ft_expand(ms->ms_env, *ms->vars, p->list->data));
			p->tmp_str = ft_strdup(p->str);
		}
		else
		{
			p->str = ft_strjoin_wo_leaks(p->tmp_str, p->list->data);
			p->tmp_str = ft_strdup(p->str);
		}
		p->list = p->list->next;
	}
	if (p->list->status == IN_SQUOTE)
		p->str = ft_strjoin(p->tmp_str, p->list->data);
	if (p->tmp_str)
		free (p->tmp_str);
}

void	ft_is_redir_type(t_ms *ms, t_counters *p)
{
	ms->cmds[p->i].redirs[p->k].type = p->list->type;
	if (!p->list->next)
	{
		printf("bash: syntax error near unexpected token `newline'\n");
		return ;
	}
	p->list = p->list->next;
	while (p->list->type == WHITE_SPACE)
		p->list = p->list->next;
	if (p->list->type == DOUBLE_QUOTE || p->list->type == SINGLE_QUOTE)
	{
		if (p->list->type == SINGLE_QUOTE)
			ft_is_redir_single_quote(ms, p);
		else if (p->list->type == DOUBLE_QUOTE)
			ft_is_redir_double_quote(ms, p);
		ms->cmds[p->i].redirs[p->k].arg = ft_strdup(p->str);
	}
	else
	{	
		ms->cmds[p->i].redirs[p->k].arg = ft_strdup(p->list->data);
	}
	p->j--;
	p->k++;
}

void	ft_is_env_and_squote(t_ms *ms, t_counters *p)
{
	char	*str_expanded; 
	char *tmp_arg;
	
	str_expanded = NULL;
	str_expanded = ft_expand(ms->ms_env, *ms->vars, p->list->data);
	if (ms->cmds[p->i].args[p->j] && str_expanded)
	{
		tmp_arg = ft_strdup(ms->cmds[p->i].args[p->j]);
		ms->cmds[p->i].args[p->j]= ft_strjoin(tmp_arg, str_expanded);
		free(tmp_arg);
	}
	else if (!ms->cmds[p->i].args[p->j])
		ms->cmds[p->i].args[p->j] = ft_strdup(str_expanded);
	free (str_expanded);
}

void	ft_if_redir_dif_pipe(t_ms *ms, t_counters *p)
{
	
	p->str = NULL;
	char *tmp_arg;
	char *tmp_list;
	if (p->list->type == ENV && p->list->status != IN_SQUOTE)
		ft_is_env_and_squote(ms, p);
	else if (p->list->type == SINGLE_QUOTE)
		ft_is_in_single_quote(ms, p);
	else if (p->list->type == DOUBLE_QUOTE)
		ft_is_in_double_quote(ms, p);
	else if (ft_is_redir(p->list->type))
		ft_is_redir_type(ms, p);
	else if (ms->cmds[p->i].args[p->j] != NULL)
	{
		tmp_arg = ft_strdup(ms->cmds[p->i].args[p->j]);
		tmp_list = ft_strdup(p->list->data);
		ft_free(ms->cmds[p->i].args[p->j]);
		ms->cmds[p->i].args[p->j] = ft_strjoin(tmp_arg, tmp_list);
		ft_free(tmp_arg);
		ft_free(tmp_list);
		
	}
	else if (p->list->type != WHITE_SPACE)
	{
		ms->cmds[p->i].args[p->j] = ft_strdup(p->list->data);
		if (ft_is_dot_comma(ms->cmds[p->i].args[p->j])
			&& p->list->status != IN_SQUOTE && p->list->status != IN_DQUOTE)
			ms->dot_comma_flag = true;
	}
}

void	ft_parser_count_pipes(t_ms *ms, t_counters *p)
{
	while (p->i <= (ms->n_pipes * 2))
	{
		ms->cmds[p->i].args
			= ft_calloc(ms->count_args[p->i] + 1, sizeof(t_command));
		ms->cmds[p->i].in = 0;
		ms->cmds[p->i].out = 1;
		ms->cmds[p->i].status = -1;
		ms->cmds[p->i].err = false;
		if (!ms->cmds[p->i].args)
			return ;
		p->i++;
	}
}
