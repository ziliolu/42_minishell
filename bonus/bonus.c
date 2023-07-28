/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 23:41:39 by ialves-m          #+#    #+#             */
/*   Updated: 2023/07/28 15:55:24 by lpicoli-         ###   ########.fr       */
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

// int	ft_recursive()
// {
	
// }

bool	ft_find_op(char *str, int i, char c)
{
	if (str[i + 1] && str[i + 1] == c)
		return (true);
	return (false);
}

typedef struct s_cmd
{
	char			*str; // &&			// echo a
	enum e_status status; // GENERAL	// GENERAL
	enum e_token	type; // AND		// CMD
}	t_cmd;

t_cmd *ft_bonus_parser(char *str)
{
	int		i;
	//int		j;
	int		k;
	t_cmd	*cmd;
	enum e_status status;

	status = GENERAL;
	i = 0;
	k = 0;

	//echo a && (echo b || echo c)
	cmd = ft_calloc(1, sizeof(cmd));
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
			k++;
		}
		if (ft_find_op(str, i, '&'))
		{
			k++;
			cmd[k].str = "&&";
			cmd[k].type = AND;
			cmd[k].status = status;
			k++;
			i++;
		}
		else if (ft_find_op(str, i, '|'))
		{
			k++;
			cmd[k].str = "||";
			cmd[k].type = OR;
			cmd[k].status = status;
			k++;
			i++;
		}
		else
		{
			if(!tmp)
				tmp = ft_strdup(cmd[k].str);
			else
			{
				ft_free(cmd[k].str);
				cmd[k].str = ft_charjoin(tmp, str[i]);
				tmp = ft_strdup(cmd[k].str);
			}	
			cmd[k].type = CMD;
			cmd[k].status = status;
		}
		i++;
	}
	return(cmd);
}

void ft_print_cmds_prompt(t_cmd *cmd)
{
	int i;

	i = 0;
	printf("\n|--------> PROMPT COMMANDS *BONUS* <----------|\n");
	while(cmd[i].str)
	{
		printf("|\t\t\t\t\t|\n");
		printf("|\t\tCOMMAND %i\t\t|\n", i);
		printf("|\t\t%s\t\t|\n", cmd[i].str);
		printf("|\t\t%s\t\t|\n", ft_token_status(cmd[i].status));
		printf("|\t\t%s\t\t|\n", ft_token_type(cmd[i].type));
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
	t_cmd *cmd;

	// cmd = ft_calloc(1, sizeof(cmd));
	prompt = "\e[93mminishell\e[31m_\e[93mb\e[32mo\e[92mn\e[34mu\e[94ms\e[31m$\033[0m ";
	while (1)
	{
		read_content = readline(prompt);
		cmd = ft_bonus_parser(read_content);
		ft_print_cmds_prompt(cmd);
		printf("And: %d\n", ft_and_operator(read_content));
		printf("Or: %d\n", ft_or_operator(read_content));
		ft_free(read_content);
	}
}