/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_lst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 11:39:38 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/04 15:48:14 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_env(t_command *cmd, t_lst *lst)
{
	if(cmd->args[1])
	{
		printf("env: '%s': No such file or directory\n", cmd->args[1]);
		g_exit_status = 127;
		return ;
	}
	ft_print_list(lst);
}
