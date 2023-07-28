/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 23:41:39 by ialves-m          #+#    #+#             */
/*   Updated: 2023/07/28 00:15:14 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minishell.h"

// ls && echo oi || ls
void	ft_bonus(char **argv)
{
	int	i;
	int	j;
	int	and;
	int	or;
	int	arg_size;

	
	i = 0;
	while (argv[i])
	{
		j = 0;
		arg_size = ft_strlen(argv[i]);
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] == '&')
				if (argv[i][j + 1] && argv[i][j + 2] && argv[i][j + 1] == '&')	
					and++;
		}
	}
}

int	main(int argc, char **argv, char **system_env)
{
	
}