/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:36:32 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/18 14:38:05 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include <signal.h>

//t_env **ms_env;
int g_exit_status;

int main(int argc, char **argv, char **system_env)
{
	char	*prompt;
	char 	*tmp_prompt;
	char 	*read_content;
	//char	*tmp_read_content;
	t_ms	ms;

	(void)argc;
	(void)argv;
	prompt = "minishell> ";
	ms.is_print = 0;
	ms.print_cmd = 0;
	ms.status = 0;
	ms.dot_comma_flag = false; 
	ft_create_env(&ms, system_env); 
	ft_init_ms(&ms, system_env);
	ms.vars = (t_lst **)ft_calloc(1, sizeof(t_lst *));
	while (1)
	{
		ms.processes = 0;
		ft_handle_signals();
		read_content = readline(prompt);
		if(!read_content) // for handling ctrl + d -> its seen as an eof and not as a signal
		{
			printf("exit\n");
			ft_free_env(&ms);
			ft_free_array(ms.paths);
			exit(0);
		}

		tmp_prompt = ft_strtrim(read_content, " ");
		//free (tmp_read_content);
		if(ft_strcmp(tmp_prompt, "") != 0)
		{
			add_history(read_content);
			ms.read_size = ft_strlen(read_content);
			free(read_content);
			read_content = ft_broken_cmds(&ms, tmp_prompt);
			if(!read_content)
				continue ;
			if(ft_is_there_quote(read_content))
				if(!ft_is_arg_valid(&ms, read_content)) //caso as aspas/plicas não tenham fechamento
					continue ; // pular restante e voltar a mostrar o prompt 
			if(read_content[0] != '\0')
			{
				ft_lexer(&ms, read_content);
   				ms.ms_argv = ft_split(read_content, ' ');
				ft_count_args(&ms, *ms.lexed_list);
				ft_parser(&ms, *ms.lexed_list);
				if(ft_cmd_args_validation(&ms))
				{
					if(ms.is_print)
						ft_print_tokens(&ms, *ms.lexed_list);
					//ft_free_elem_list(*ms.lexed_list);
					// free(ms.lexed_list);
					if (!ms.dot_comma_flag) // Aqui é verificada uma flag (ativada no parser) para determinar se ; é aceite ou não
						ft_run_cmds(&ms);
					else
					{
						ft_error(&ms, "minishell: syntax error near unexpected token `;'\n", NULL);
						ms.dot_comma_flag = false;
					}	
				}
			}
			ft_wait(&ms);
			// free(read_content); //teste

			ft_free_array(ms.ms_argv);
			ft_free_array(ms.ms_env_array);
			ft_free_cmds(&ms);
			free(ms.count_args);
			free(tmp_prompt);	
			ft_free_elem_list(*ms.lexed_list);
			free(ms.lexed_list);
			
		}
	}
	return (0);
}

void ft_wait(t_ms *ms)
{
	if(waitpid(ms->pid, &ms->status, 0) != -1)
	{
		if(WIFEXITED(ms->status))
			g_exit_status = WEXITSTATUS(ms->status);		
		else if(WIFSIGNALED(ms->status) && g_exit_status == 0)
			g_exit_status = 128 + WTERMSIG(ms->status);
		ms->processes--;
	}
	while(ms->processes)
	{
		wait(0);
		ms->processes--;
	}
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

bool ft_is_absolute_path(char *str)
{
	if(!str)
		return(false);
	if(str[0] == '/' || (str[0] == '.' && str[1] == '/')
		|| (str[0] == '.' && str[1] == '.' && str[2] == '/') 
		|| (str[0] == '~' && str[1] == '/'))
	 	return (true);
	return (false);
}

/*
    1. caminho absoluto (./  / ../)
	2. caminho relativo 
*/
char *ft_getenv(t_ms *ms, char *name)
{
	t_lst *list;

	list = ms->ms_env;
	while(list)
	{
		if(ft_strcmp(list->name, name) == 0)
			return(list->info);
		list = list->next;
	}
	return(NULL);
}
