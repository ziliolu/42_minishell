/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 23:41:39 by ialves-m          #+#    #+#             */
/*   Updated: 2023/07/28 00:10:35 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minishell.h"

// ls && echo oi || ls
void	ft_bonus(char **argv)
{
	int	i;
	int	j;
	int	tmp_and;
	int	and;
	int	tmp_or;
	int	or;

	i = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] == '&' && tmp_and == 0)
				if (argv[i][j + 1] == '&')	
					and = 1;
			else if (tmp_and == 1)
			{
				and++;
				tmp_and = 0;
			}
		}
	}
}

int	main(int argc, char **argv, char **system_env)
{
	
}