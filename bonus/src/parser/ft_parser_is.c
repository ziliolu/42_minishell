/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_is.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 12:06:12 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/26 18:14:56 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_parser_is(t_ms *ms, t_counters *p)
{
	char	*tmp_arg;
	char	*tmp_list;

	p->str = NULL;
	p->tmp_str = NULL;
	tmp_arg = NULL;
	tmp_list = NULL;
	if (p->list->type == ENV && p->list->status != IN_SQUOTE)
		ft_is_env_and_squote(ms, p);
	else if (p->list->type == SINGLE_QUOTE)
		ft_is_in_single_quote(ms, p);
	else if (p->list->type == DOUBLE_QUOTE)
		ft_is_in_double_quote(ms, p);
	else if (ft_is_redir(p->list->type))
		ft_is_redir_type(ms, p);
	else if (ms->cmds[p->i].args[p->j] != NULL)
		ft_parser_is_not_null(ms, p, tmp_arg, tmp_list);
	else if (p->list->type != WHITE_SPACE)
	{
		free(ms->cmds[p->i].args[p->j]);
		ms->cmds[p->i].args[p->j] = ft_strdup(p->list->data);
		if (ft_is_dot_comma(ms->cmds[p->i].args[p->j])
			&& p->list->status != IN_SQUOTE && p->list->status != IN_DQUOTE)
			ms->dot_comma_flag = true;
	}
}
