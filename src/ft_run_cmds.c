/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_cmds.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 10:01:08 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/06/20 14:49:09 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define WRITE_END   1
#define READ_END    0
#include "../includes/minishell.h"

void ft_run_cmds(t_ms *ms)
{
    int i;
    int k;

    i = 0;
    k = 0;
    while(i <= ms->n_pipes)
    {
        if(ms->cmds[i].redirs[k].arg != NULL)
        {
            while(k < ft_count_redirs_cmd(&ms->cmds[i]))  
            {
                if(ms->cmds[i].redirs[k].type == REDIR_OUT || ms->cmds[i].redirs[k - 1].type == D_REDIR_OUT)
                    open(ms->cmds[i].redirs[k].arg, O_CREAT | O_APPEND | O_WRONLY, 0777);
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
        // if(ms->cmds[i].operator == PIPE_LINE) // OR + AND operators here
        //     ft_pipeline(ms, &ms->cmds[i], i);
        // else
        //     ft_is_executable(ms, &ms->cmds[i]);   
        i++;
    }
    if(ms->n_pipes > 0)
        ft_pipeline(ms);
    else
        ft_is_executable(ms, &ms->cmds[0]);
}

//ls | grep h |

void ft_pipeline(t_ms *ms)
{
    int **fds = (int **)malloc(sizeof(int *) * ms->n_pipes);
    pid_t pid;
    int i;
    int j;

    i = 0;
    while(i < ms->n_pipes)
    {
        fds[i] = (int *)malloc(sizeof(int) * 2);
        i++;
    }

    i = 0;
    while(i < ms->n_pipes)
    {
        pipe(fds[i]);
        
        pid = fork();
        if(pid == 0)
        {
            //fechar entradas e saidas 
            //desnecessarios dos outros pipes
            
            //pipe[0][0] V
            //pipe[0][1] V

            //ls | grep h | grep o
            j = 0;
            while(j < ms->n_pipes)
            {
                if(j != i) //nao fechar do pipe atual
                close(fds[j][1]);
                close(fds[j][0]);
                j++;
            }
            if(i == 0) //primeiro comando 
            {
                close(fds[i][0]); // fecha read
                dup2(fds[i][1], STDOUT_FILENO); //alterar stdout - escrita do pipe
                close(fds[i][1]);
            }
            else if(i > 0 && i < ms->n_pipes) //comandos intermediarios
            {
                
                close(fds[i][0]); //fds[1][0]
                dup2(fds[i - 1][0], STDIN_FILENO); //leitura do comando anterior
                close(fds[i - 1][0]);
                dup2(fds[i][1], STDOUT_FILENO); //escrita para o proximo comando
                close(fds[i][1]);
                
            }
            else if(i == ms->n_pipes) // ultimo comando
            {
                close(fds[i][0]);
                close(fds[i][1]);
                dup2(fds[i - 1][0], STDIN_FILENO);
                close(fds[i - 1][0]);
            } 
            ft_is_executable(ms, &ms->cmds[i]); //cmd[i = 1]
        }
        i++;
    }
}

//ls | grep h | grep o 

//ls -> altera o out 
// grep h -> alterar o in e o out 
// grep o -> alterar in

// void ft_pipeline(t_ms *ms, t_command *cmd, int i)
// {
//     int fd1[2];
//     //int status, pid;
	
//     pipe(fd1);                 /* comunica ls y grep */
	
//     //pid = fork();       		
//     close(fd1[READ_END]);
//     cmd->out = fd1[WRITE_END];
//         //dup2(fd1[WRITE_END], STDOUT_FILENO); 
// 	close(fd1[WRITE_END]);
//     ft_is_executable(ms, cmd);
                         

//     close(fd1[WRITE_END]);    /* extremo no necesario ya */
//     ms->cmds[i + 1].in = fd1[READ_END];
//     //dup2(fd1[READ_END], STDIN_FILENO);
//     close(fd1[READ_END]);
//     //ft_is_executable(ms, &ms->cmds[i + 1]);

//     //wait(&status);
// }

// void ft_pipeline(t_ms *ms, t_command *cmd, int i)
// {
//     int fd[2];
//     int pid;
    
//     pipe(fd);

//     pid = fork();

//     if(pid == 0)
//     {
//         close(fd[0]);
//         ms->cmds[i].out = fd[1];
//         close(fd[1]);
//         ft_is_executable(ms, cmd);
//     }
//     else
//     {
//         close(fd[1]);
//         ms->cmds[i + 1].in = fd[0];
//         close(fd[0]); 
//     }
// }

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