/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:36:32 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/06/05 18:54:32 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_env **ms_env;

int main(int argc, char **argv, char **system_env)
{
	 
	char *prompt;
	char *read_content;
	t_ms ms;

	(void)argc;
	(void)argv;
	ft_env(system_env); 

	prompt = "minishell> ";
	while (1)
	{
		read_content = readline(prompt);
		add_history(read_content);
		if(ft_strcmp(ft_strtrim(read_content, " "), "exit") == 0)
			break ;
		else if(!ft_is_arg_valid(&ms, read_content))
			continue ;
		else if(read_content[0] != '\0')
		{
			ft_init_ms(&ms, system_env, read_content);
			ft_is_variable(&ms);
			ft_is_executable(&ms);
		}
	}
	return (0);
}

bool ft_is_variable(t_ms *ms)
{
	int i;
	int pos;

	i = 0;
	pos = 0;

	while(ms->ms_argv[i] != ' ')
	{
		if(ms->ms_argv[i] == '=' && ms->ms_argv[i + 1] != ' ')
		{
			pos = i;	
			break ; 		
		}
		i++;
	}
	if(pos == 0)
		return (false);	
	if
\\
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
bool ft_is_executable(t_ms *ms)
{
	int i;

	i = 0;
	if(ft_is_absolute_path(ms->ms_argv[0]))
	{
		if(access(ms->ms_argv[0], X_OK) == 0)
		{
			fork();
			execve(ms->ms_argv[0], ms->ms_argv, ms->system_env);
			return (true);
		}
		return (false);
	}
	while(ms->paths[i])
	{
		if(access(ft_strjoin(ms->paths[i], ms->ms_argv[0]), X_OK) == 0)
		{
			pid_t pid;

			pid = fork();
			if(pid == 0)
				execve(ft_strjoin(ms->paths[i], ms->ms_argv[0]), ms->ms_argv, ms->system_env);
			wait(&pid);
			return (true);
		}
		i++;
	}
	return (false);
}

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
char *ft_getenv(char *name)
{
	t_env *list;

	list = *ms_env;
	while(list)
	{
		if(ft_strcmp(list->name, name) == 0)
			return(list->info);
		list = list->next;
	}
	return(NULL);
}