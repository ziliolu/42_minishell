/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 23:41:39 by ialves-m          #+#    #+#             */
/*   Updated: 2023/07/28 01:02:12 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/bonus.h"

int	ft_and_operator(char *read_content)
{
	t_and	a;

	a.j = 0;
	a.op_and = 0;
	a.arg_size = ft_strlen(read_content);
	while (read_content[a.j] != '\0')
	{
		if (read_content[a.j] == '&')
		{
			a.op_tmp++;
			if (a.op_tmp == 2)
				a.op_and++;
			else if (a.op_tmp == 3)
			{}	printf("minishel_bonus: syntax error near unexpected token `&'");
		}
		else
		{
			a.op_tmp = 0;
		}
		a.j++;
	}
	return (a.op_and);
}
int	ft_or_operator(char *read_content)
{
	t_or	o;

	o.i = 0;
	o.op_or = 0;
	o.arg_size = ft_strlen(read_content);
	while (read_content[o.i] != '\0')
	{
		if (o.arg_size > 1 && read_content[o.i] == '|')
			if (read_content[o.i + 1] && read_content[o.i + 1] == '|')	
				o.op_or++;
		o.i++;
	}
	return (o.op_or);
}

int	main(int argc, char **argv, char **system_env)
{
	(void) argc;
	(void) argv;
	(void) system_env;
	char	*prompt;
	char	*read_content;

	prompt = "\e[93mminishell\e[31m_\e[93mb\e[32mo\e[92mn\e[34mu\e[94ms\e[31m$\033[0m ";
	while (1)
	{
		read_content = readline(prompt);
		printf("And: %d\n", ft_and_operator(read_content));
		printf("Or: %d\n", ft_or_operator(read_content));
	}
}