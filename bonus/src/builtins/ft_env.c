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

bool	ft_find_in_array(char *str, char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		if (ft_strcmp(str, array[i]) == 0)
			return (true);
		i++;
	}
	return (false);
}

void	ft_env(t_ms *ms, t_command *cmd, t_lst *lst)
{
	if (!ms->paths)
	{
		ft_printf("minishell: env: No such file or directory\n");
		g_exit_status = 127;
		return ;
	}
	else if (!ft_find_in_array("/bin", ms->paths)
		&& !ft_find_in_array("/usr/bin", ms->paths))
	{
		ft_printf("Command 'env' is available in the following places\n \
* /bin/env\n * /usr/bin/env\nThe command could not be located because \
'/bin:/usr/bin' is not included in the PATH environment variable.\n");
		ft_printf("env: command not found\n");
		g_exit_status = 127;
		return ;
	}
	if (cmd->args[1])
	{
		printf("env: '%s': No such file or directory\n", cmd->args[1]);
		g_exit_status = 127;
		return ;
	}
	ft_print_list(lst);
}
