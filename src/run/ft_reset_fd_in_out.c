/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reset_fd_in_out.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 10:01:08 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/08/05 15:50:12 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_reset_fd_in_out(t_ms *ms)
{
	dup2(ms->std_out, STDOUT_FILENO);
	dup2(ms->std_in, STDIN_FILENO);
}

void	ft_reset_heredoc(t_ms *ms, int i)
{
	dup2(ms->std_out_arr[i], STDOUT_FILENO);
	dup2(ms->std_in_arr[i], STDIN_FILENO);
}
