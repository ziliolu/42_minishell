/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_cmds.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 10:01:08 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/06/23 15:53:30 by lpicoli-         ###   ########.fr       */
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
            /* if(ms->cmds[i + 1].type != PIPE_LINE && ms->n_pipes == 0)
            {
                ft_is_executable(ms, &ms->cmds[i]);
            }
			else */ 

			if(ms->cmds[i + 1].type == PIPE_LINE) // primeiro comando
            {

                if(ms->cmds[i].out == 1)
                    ms->cmds[i].out = ms->cmds[i + 1].fd[1];
                else
                    close(ms->cmds[i + 1].fd[1]);
                
               // ft_is_executable(ms, &ms->cmds[i]);
            }
            if(ms->cmds[i - 1].type == PIPE_LINE) //ultimo comando (in)
            {
                //if(ms->cmds[i].in == 0)
                ms->cmds[i].in = ms->cmds[i - 1].fd[0];
                
                //ms->cmds[i].out = 1;
                //close(ms->cmds[i - 1].fd[0]);
                // close(ms->cmds[i].fd[0]);
                // close(ms->cmds[i].fd[1]);
            }
            ft_is_executable(ms, &ms->cmds[i]);
        }
        i++;
    }
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
    int **fds = (int **)malloc(sizeof(int *) * ms->n_pipes);
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
        fds[i] = (int *)malloc(sizeof(int) * 2);
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
    str = malloc(sizeof(char));
    read_content = malloc(sizeof(char));
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