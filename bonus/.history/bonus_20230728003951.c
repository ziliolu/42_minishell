/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 23:41:39 by ialves-m          #+#    #+#             */
/*   Updated: 2023/07/28 00:39:51 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/bonus.h"

int	ft_and_operator(char **read_content)
{
	int	j;
	int	and;
	int	arg_size;

	
	j = 0;
	and = 0;
	arg_size = ft_strlen(read_content);
	while (read_content[j] != '\0')
	{
		if (arg_size > 1 && read_content[j] == '&')
			if (read_content[j + 1] && read_content[j + 1] == '&')	
				and++;
		j++;
	}
	return (add);
}
int	ft_or_operator(char **read_content)
{
	int	i;
	int	or;
	int	arg_size;

	
	i = 0;
	or = 0;
	arg_size = ft_strlen(read_content);
	while (read_content[i] != '\0')
	{
		if (arg_size > 1 && read_content[i] == '&')
			if (read_content[i + 1] && read_content[i + 1] == '&')	
				or++;
		i++;
	}
	return (or);
}

int	main(int argc, char **argv, char **system_env)
{
	
	printf("And: %d\n", ft_and_operator(argv));
}