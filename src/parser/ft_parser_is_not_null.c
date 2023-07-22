/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_is_not_null.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 12:06:12 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/22 14:53:19 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_parser_is_not_null(t_ms *ms, t_counters *p, \
	char *tmp_arg, char *tmp_list)
{
	tmp_arg = ft_strdup(ms->cmds[p->i].args[p->j]);
	tmp_list = ft_strdup(p->list->data);
	ft_free(ms->cmds[p->i].args[p->j]);
	ms->cmds[p->i].args[p->j] = ft_strjoin(tmp_arg, tmp_list);
	ft_free(tmp_arg);
	ft_free(tmp_list);
}
