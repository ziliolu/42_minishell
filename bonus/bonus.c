/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 23:41:39 by ialves-m          #+#    #+#             */
/*   Updated: 2023/07/28 14:19:44 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/bonus.h"
#include "includes/minishell.h"
#include <stdbool.h>

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
			{
				printf("minishel_bonus: syntax error near unexpected token `&'\n");
				exit (2);
			}
		}
		else
			a.op_tmp = 0;
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
		if (read_content[o.i] == '|')
		{
			o.op_tmp++;
			if (o.op_tmp == 2)
				o.op_or++;
			else if (o.op_tmp == 3)
			{
				printf("minishel_bonus: syntax error near unexpected token `|'\n");
				exit (2);
			}
		}
		else
			o.op_tmp = 0;
		o.i++;
	}
	return (o.op_or);
}

int	ft_recursive()
{
	
}

bool	ft_find_op(char *str, int i, char c)
{
	if (str[i + i] && str[i + i] == c)
		return (true);
	return (false);
}

typedef struct s_cmd
{
	char			*str; // &&			// echo a
	enum e_status status; // GENERAL	// GENERAL
	enum e_token	type; // AND		// CMD
}	t_cmd;



void	ft_bonus_parser(char *str)
{
	int		i;
	int		j;
	int		k;
	t_cmd	*cmd;
	enum e_status status;

	status = GENERAL;
	i = 0;

	//echo a && (echo b || echo c)
	while (str[i])
	{
		if(str[i] == P_OPEN || str[i] == P_CLOSE)
		{
			k++;
			if(str[i] == P_OPEN)
			{
				cmd[k].str = "(";
				cmd[k].type = P_OPEN;
			}
			if(str[i] == P_CLOSE)
			{
				cmd[k].str = ")";
				cmd[k].type = P_CLOSE;
			}
			cmd[k].status = status;
			status = IN_P;
		}
		if (ft_find_op(str, i, '&'))
		{
			i += 2;
			k++;
			cmd[k].str = "&&";
			cmd[k].type = AND;
			cmd[k].status = status;
		}
		else if (ft_find_op(str, i, '|'))
		{
			i += 2;
			k++;
			cmd[k].str = "||";
			cmd[k].type = OR;
			cmd[k].status = status;
		}
		cmd[k].str = ft_charjoin(cmd[k].str, str[i]);
		cmd[k].status = status;
		cmd[k].
		i++;
	}
}

// void	ft_resolve()
// {
// 	ft_find_next_op()
// 	{
// 		if (parentisses -> ft_recursive())
// 		return (comando -> minishell)
// 	}
// }




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