/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_env_in_quotes.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 12:06:12 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/22 13:16:58 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_is_env_in_quotes(t_counters *p, char *exp_or_data, char *tmp_str)
{
	if (!tmp_str)
	{
		p->str = exp_or_data;
		p->tmp_str = exp_or_data;
	}
	else
	{
		ft_free (p->str);
		p->str = ft_strjoin_wo_leaks(tmp_str, exp_or_data);
		ft_free(tmp_str);
		tmp_str = ft_strdup(p->str);
	}
}
