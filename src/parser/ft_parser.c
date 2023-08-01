/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 17:56:37 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/22 11:08:46 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_parser(t_ms *ms, t_elem *list)
{
	int			counter;
	t_counters	p;

	ms->spaces_flag = 0;
	counter = ft_count_tokens(list);
	ms->n_pipes = ft_count_pipes(list);
	ms->cmds = ft_calloc(ms->n_pipes * 2 + 2, sizeof(t_command));
	p.i = 0;
	p.j = 0;
	p.k = 0;
	p.list = list;
	if (!ms->cmds)
		return ;
	ft_parser_count_pipes(ms, &p);
	p.tmp_str = NULL;
	p.i = 0;
	ft_parser_while_dif_null(ms, &p, counter);
}
