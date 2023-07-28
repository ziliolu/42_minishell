/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 23:41:39 by ialves-m          #+#    #+#             */
/*   Updated: 2023/07/28 00:34:05 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minishell.h"

// ls && echo oi || ls
int	ft_and_operator(char **read_content)
{
	int	i;
	int	j;
	int	and;
	int	arg_size;

	
	i = 0;
	and = 0;
	arg_size = ft_strlen(read_content[i]);
	while (read_content[i][j] != '\0')
	{
		if (arg_size > 1 && read_content[i][j] == '&')
			if (read_content[i][j + 1] && read_content[i][j + 1] == '&')	
				and++;
		j++;
	}
	i++;
	return (add);
}

int	main(int argc, char **argv, char **system_env)
{
	
	printf("And: %d\n", ft_and_operator(argv));
}