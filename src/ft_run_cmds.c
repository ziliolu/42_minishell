/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_cmds.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 10:01:08 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/06/19 18:00:57 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
       ft_is_executable(ms, &ms->cmds[i]);
       if(ms->cmds[i].operator == PIPE_LINE) // OR + AND operators here
            ft_pipeline(ms, i);
        i++;
    }
}

//echo hello | grep h
void ft_pipeline(t_ms *ms, int i)
{
    int fd[2];
    
    pipe(fd);
    
    ms->cmds[i].out = fd[1];
    ms->cmds[i + 1].in = fd[0];  
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