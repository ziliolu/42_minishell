/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_cmds.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 10:01:08 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/06 22:48:17 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void ft_run_cmds(t_ms *ms)
{
    
    int i;
    int k;

    i = 0;
    k = 0;
    // if(ms->print_cmd == 1)
    //     ft_print_command_nodes(ms, ms->n_pipes);
    ms->std_in = dup(STDIN_FILENO);
	ms->std_out = dup(STDOUT_FILENO);
    ms->ms_env_array = ft_list_to_array(ms);
	ft_init_pipes(ms);
    while(ms->cmds[i].type)
    {
        ms->cmds[i].in = 0;
        ms->cmds[i].out = 1;
        k = 0;
        if(ms->cmds[i].type == CMD)
        {
            if(ms->cmds[i].redirs[k].arg != NULL)
            {
                while(k < ft_count_redirs_cmd(&ms->cmds[i]))  
                {
                    if(ms->cmds[i].redirs[k].type == REDIR_OUT || ms->cmds[i].redirs[k - 1].type == D_REDIR_OUT)
                        ms->cmds[i].out = open(ms->cmds[i].redirs[k].arg, O_CREAT | O_APPEND | O_WRONLY, 0777);
                    else if (ms->cmds[i].redirs[k].type == REDIR_IN)
                        ms->cmds[i].in = open(ms->cmds[i].redirs[k].arg, O_RDONLY, 0777);
                    else if (ms->cmds[i].redirs[k].type == HERE_DOC)
                        ft_is_heredoc(&ms->cmds[i], &ms->cmds[i].redirs[k]);
                    k++;
                }
                if(ms->cmds[i].redirs[k - 1].type == REDIR_OUT)
                    ms->cmds[i].out = open(ms->cmds[i].redirs[k - 1].arg, O_CREAT | O_TRUNC | O_WRONLY, 0777);
                else if(ms->cmds[i].redirs[k - 1].type == D_REDIR_OUT)
                    ms->cmds[i].out = open(ms->cmds[i].redirs[k - 1].arg, O_CREAT | O_APPEND | O_WRONLY, 0777);
            }

			if(ms->cmds[i + 1].type == PIPE_LINE) // primeiro comando
            {

                if(ms->cmds[i].out == 1)
                    ms->cmds[i].out = ms->cmds[i + 1].fd[1];
                else
                    close(ms->cmds[i + 1].fd[1]);
                
            }
			
            if(i > 0 && ms->cmds[i - 1].type == PIPE_LINE) //ultimo comando (in)
            {
                ms->cmds[i].in = ms->cmds[i - 1].fd[0];
            }
            // verificacao do formato "nome=maria" p/ adicionar na lista de argumentos
            // if(ft_strchr_vars(ms->cmds[i].args[0], '='))
            // {
            //     printf("é um argumento!\n");
            //     ft_add_local_variable(ms->vars, ft_strtrim(ms->cmds[i].args[0], "="), ft_strtrim(ft_strchr_vars(ms->cmds[i].args[0], '='), "="));
            // }
            if(ms->cmds[i].type != PIPE_LINE)
            {
                ft_change_standard_in_out(&ms->cmds[i]);
                ft_filter_cmd(ms, &ms->cmds[i]);
                ft_reset_fd_in_out(ms);
            }
        }
        i++;
    }
}

void ft_change_standard_in_out(t_command *cmd)
{
    if(cmd->out != 1)
	{
		if(dup2(cmd->out, STDOUT_FILENO) == -1)
		{
			printf("dup2 error!\n");
			//printf("fd:%d\n", cmd->out);
		}
		close(cmd->out);
	}
	if(cmd->in != 0)
	{
		if(dup2(cmd->in, STDIN_FILENO) == -1)
			printf("dup2 error!\n");
		close(cmd->in);
	}   
}

void ft_reset_fd_in_out(t_ms *ms)
{
    dup2(ms->std_out, STDOUT_FILENO);
	dup2(ms->std_in, STDIN_FILENO);
}
    
void ft_filter_cmd(t_ms *ms, t_command *cmd)
{
    if(ft_strcmp(cmd->args[0], "echo") == 0)
        ft_echo(cmd);
    else if(ft_strcmp(cmd->args[0], "cd") == 0)
        ft_cd(ms, cmd);
    else if(ft_strcmp(cmd->args[0], "env") == 0)
        ft_print_list(ms->ms_env);
    else if(ft_strcmp(cmd->args[0], "pwd") == 0)
        printf("%s\n", ft_return_list_info(ms->ms_env, "PWD"));
    else if(ft_strchr_vars(cmd->args[0], '='))
        ft_add_node_to_list(ms, ms->vars, cmd->args[0]);
    else if(ft_strcmp(cmd->args[0], "export") == 0)
        ft_export(ms, cmd->args[1]);
    else if(ft_strcmp(cmd->args[0], "unset") == 0)
    {
        if(!ft_strchr_vars(cmd->args[1], '='))
            ft_remove_node_list(&ms->ms_env, cmd->args[1]);
    }
    else if(ft_strcmp(cmd->args[0], "args") == 0)
        ft_print_local_variables(ms->vars);
    else if(!ft_is_executable(ms, cmd))
    {
        printf("minishell: command not found: %s\n", cmd->args[0]);
        g_exit_status = 127;
    }
	ft_free_array(ms->ms_env_array);

}

void ft_init_pipes(t_ms *ms)
{
    int i;

    i = 0;
    while(ms->cmds[i].type)
    {
        if(ms->cmds[i].type == PIPE_LINE)
		{
            pipe(ms->cmds[i].fd);
			//printf("Pipe %d --> fd[0]=%d fd[1]=%d\n", i, ms->cmds[i].fd[0], ms->cmds[i].fd[1]);
		}
		i++;
    }
}

void ft_pipeline(t_ms *ms)
{
    int **fds = (int **)ft_calloc(ms->n_pipes, sizeof(int *));
    //pid_t pid;
    int i;
    //int j;
	int out;
    int in;

	out = dup(STDOUT_FILENO);
    in = dup(STDIN_FILENO);
    i = 0;
    while(i < ms->n_pipes)
    {
        fds[i] = (int *)ft_calloc(2, sizeof(int));
        i++;
    }

    i = 0;
    //printf("ms pipes %d\n", ms->n_pipes);
    while(i < ms->n_pipes + 1)
    {
        pipe(fds[i]);
        //funcao abrir todos os pipes
        //pid = fork();
		//if (pid == 0)
		//{
		//	printf("Child 1\n");
		//	printf("fds[0][0] = %d\n", fds[i][0]);
		//	printf("fds[0][1] = %d\n", fds[i][1]);
		//	printf("\n");
			
		//}
        //if(pid == 0)
        //{
            //fechar entradas e saidas 
            //desnecessarios dos outros pipes
            
            //pipe[0][0] V
            //pipe[0][1] V

            //ls | grep h | grep o
            // j = 0;
            // while(j < ms->n_pipes)
            // {
            //     if(j != i) //nao fechar do pipe atual
			// 	{
			// 		close(fds[j][1]);
			// 		close(fds[j][0]);
			// 	}
			// 	j++;
            // }
            if(i == 0) //primeiro comando 
            {
				//printf("Primeiro Comando\n");
                //close(fds[i][0]); // fecha read
                dup2(fds[i][1], STDOUT_FILENO); //alterar stdout - escrita do pipe
                close(fds[i][1]);
				//printf("Saiu do primeiro comando\n");

            }
            else if(i > 0 && i < ms->n_pipes) //comandos intermediarios
            {
				printf("Segundo Comando\n");
                close(fds[i][0]); //fds[1][0]
                dup2(fds[i - 1][0], STDIN_FILENO); //leitura do comando anterior
				
                close(fds[i - 1][0]);
                dup2(fds[i][1], STDOUT_FILENO); //escrita para o proximo comando
                
                close(fds[i][1]);
				printf("Saiu do segundo comando\n");
            }
            else if(i == ms->n_pipes) // ultimo comando
            {
				//printf("Terceiro Comando\n");
                //close(fds[i][0]);
                //close(fds[i][1]);
                dup2(fds[i - 1][0], STDIN_FILENO);
                close(fds[i - 1][0]);
				//printf("Saiu do terceiro comando\n");

            }
			if (i == 0)
				ft_is_executable(ms, &ms->cmds[i]); //cmd[i = 1]
			else if (i == 1)
			{
				dup2(out, STDOUT_FILENO);
				ft_is_executable(ms, &ms->cmds[i]);
				close(out);
                dup2(in, STDIN_FILENO);
                close(in);
			}
			//exit(0);
        //}
		//else
		//{
		//	//printf("Father\n");
		//	//while(j < ms->n_pipes)
		//	//{
		//	//	// close(fds[j][1]);
		//	//	// printf("Fechou fds[j][0] = %d\n", fds[j][0]);
				
		//	//	// close(fds[j][0]);
		//	//	// printf("Fechou fds[j][1] = %d\n", fds[j][1]);
				
		//	//	printf("Valor de j = %d\n", j);
		//	//	j++;
		//	//}
        //    while(waitpid(0, NULL, 0) > 0)
        //        continue;
		//	//printf("\n");

		//}
        i++;
    }
	//i = -1;
	//while (i++ < ms->n_pipes)
	//	wait(NULL);
}

void ft_is_heredoc(t_command *cmd, t_redirect *redir)
{
    char *eof;
    char *str;
    int fd;
    int fd2;
    char *read_content;
    char *prompt;

    (void)cmd;
    prompt = "> ";
    eof = redir->arg;
    str = ft_calloc(1, sizeof(char));
    read_content = ft_calloc(1, sizeof(char));
    while(ft_strcmp(read_content, eof) != 0)
    {
        read_content = readline(prompt);
        if(ft_strcmp(read_content, eof) == 0)
            break ;
        str = ft_strjoin(str, read_content);
        str = ft_strjoin(str, "\n");
    }
    fd = open("temp.txt", O_WRONLY|O_CREAT|O_EXCL|O_TRUNC, 0600);
    fd2 = dup(fd);
    write(fd2, str, ft_strlen(str));
    close(fd2);
    open("temp.txt", O_RDONLY);
    close(fd);
    unlink("temp.txt");
    cmd->in = fd2;
    //printf("%s\n", str);    
    //cmd->args[1] = str;
}

int ft_count_cmds(t_ms *ms)
{
    int i;
    
    i = 0;
    while(ms->cmds[i].args != NULL)
    {
        i++;
    }
    return (i);
}