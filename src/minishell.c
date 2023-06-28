/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:36:32 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/06/28 17:28:21 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include <signal.h>

//t_env **ms_env;
int g_exit_status;

int main(int argc, char **argv, char **system_env)
{
	 
	char *prompt;
	char *read_content;
	t_ms ms;

	(void)argc;
	(void)argv;

	prompt = "minishell> ";
	ms.is_print = 0;
	ms.print_cmd = 0;
	ft_create_env(&ms, system_env); 
	ft_init_ms(&ms, system_env);
	while (1)
	{
		ft_handle_signals(); 
		read_content = readline(prompt);
		if(!read_content) // for handling ctrl + d -> its seen as an eof and not as a signal
		{
			printf("exit\n");
			exit(0);
		}
		if(ft_strcmp(read_content, "") != 0)
		{
			add_history(read_content);
			ms.read_size = ft_strlen(read_content);
			if(ft_strcmp(ft_strtrim(read_content, " "), "exit") == 0)
				break ;
			if(ft_is_there_quote(read_content))
			{
				if(!ft_is_arg_valid(&ms, read_content)) //caso as aspas/plicas não tenham fechamento
					continue ; // pular restante e voltar a mostrar o prompt 
			}
			if(read_content[0] != '\0')
			{
				ft_lexer(&ms, read_content);
				//ft_parser();
				//ft_is_executable(&ms);
   				ms.ms_argv = ft_split(read_content, ' ');

				ft_run_cmds(&ms);
				// ft_is_variable(&ms);
			}
		}
	}
	return (0);
}

bool ft_is_variable(t_ms *ms)
{
	int j;
	int pos;

	j = 0;
	pos = 0;
	printf("is a variable! \n");
	while(ft_is_valid_character(ms->ms_argv[0][j]))
		j++;
	if(ms->ms_argv[0][j] == '=')
		pos = j;	 		
	if(pos == 0)
		return (false);
	printf("valid info:: %d\n", ft_is_valid_info(ms, pos + 1));
	return(true);
}

bool ft_is_valid_info(t_ms *ms, int j)
{
	char *var_info;
	char *str;

	var_info = ft_calloc(ft_strlen(ms->ms_argv[0]), sizeof(char));
	while(ms->ms_argv[0][j])
	{
		if(ms->ms_argv[0][j] == '\"')
		{
			str = ft_search_for_end(ms->ms_argv[0], '\"', j);
			if(str != NULL)
				var_info = ft_strjoin(var_info, str);
			while (ms->ms_argv[0][j] != '\"')
				j++;
		}
		else if(ms->ms_argv[0][j] == '\'')
		{
			str = ft_search_for_end(ms->ms_argv[0], '\'', j);
			if(str != NULL)
				var_info = ft_strjoin(var_info, str);
			while (ms->ms_argv[0][j] != '\'')
				j++;
		}
	}
	if(str == NULL)
	{
		printf("erro!");
		return(false);
	}
	return(true);
}

char *ft_search_for_end(char *str, char c, int pos)
{
	int i;
	char *info;

	i = 1;
	while(str[pos + 1] != c)
	{
		info = ft_charjoin(info, str[i]);
		i++;
	}
	if(str[i] == c)
		return (info);
	return (NULL);
}

char *ft_charjoin(char *str, char c)
{
	int i;
	char *new_str;

	new_str = ft_calloc(2, sizeof(str));
	i = -1;
	while(str[++i])
		new_str[i] = str[i];
	new_str[++i] = c;
	new_str[++i] = '\0';
	return (new_str);	
}

#include <stdbool.h>

bool ft_is_valid_character(char character) {
    if (character >= 32 && character <= 126) {
        return true;
    }
    return false;
}

/* 
** 
--- Access function --

	X_OK -> Tests whether the file can be accessed for execution.
	F_OK -> Tests whether the file exists.
	Return value: 0 if the access is permitted, and -1 otherwise. 
	(In other words, treated as a predicate function,
	access returns true if the requested access is denied.) 
**
*/




bool ft_is_absolute_path(char *ms_argv)
{
	if(ms_argv[0] == '/' || (ms_argv[0] == '.' && ms_argv[1] == '/')
		|| (ms_argv[0] == '.' && ms_argv[1] == '.' && ms_argv[2] == '/'))
	 	return (true);
	return (false);
}

/*
    1. caminho absoluto (./  / ../)
	2. caminho relativo 
*/
char *ft_getenv(t_ms *ms, char *name)
{
	t_env *list;

	list = ms->ms_env;
	while(list)
	{
		if(ft_strcmp(list->name, name) == 0)
			return(list->info);
		list = list->next;
	}
	return(NULL);
}
