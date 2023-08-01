/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_env_in_quotes.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 12:06:12 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/24 21:01:00 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_is_env_in_quotes(t_counters *p, char *tmp_exp_or_data)
{
	if (!p->tmp_str)
	{
		if (!p->str)
			p->str = ft_strdup(tmp_exp_or_data);
		p->tmp_str = ft_strdup(tmp_exp_or_data);
	}
	else
	{
		ft_free (p->str);
		p->str = ft_strjoin_wo_leaks(p->tmp_str, tmp_exp_or_data);
		ft_free(p->tmp_str);
		p->tmp_str = ft_strdup(p->str);
	}
}
