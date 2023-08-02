/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_heredoc_inputs.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 10:01:08 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/08/02 18:27:18 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_join_heredoc_inputs(t_ms *ms, t_heredoc *h, char **tmp)
{
	char	*tmp_expand;

	tmp_expand = NULL;
	if (!*tmp)
	{
		*tmp = ft_expand_heredoc(ms->ms_env, *ms->vars, h->read_content);
		h->str = ft_expand_heredoc(ms->ms_env, *ms->vars, h->read_content);
	}
	else
	{
		ft_free(h->str);
		h->str = ft_strjoin(*tmp, "\n");
		ft_free(*tmp);
		tmp_expand = ft_expand_heredoc(ms->ms_env, *ms->vars, h->read_content);
		*tmp = ft_strjoin(h->str, tmp_expand);
		ft_free(tmp_expand);
		ft_free(h->str);
		h->str = ft_strdup(*tmp);
	}
}
