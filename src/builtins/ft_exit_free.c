/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 13:05:23 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/24 12:29:57 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_exit_free(t_ms *ms)
{

	ft_free_env(ms);
	ft_free_array(ms->paths);
	ft_free_cmds(ms);
}
