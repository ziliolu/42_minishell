/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_cmds.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 10:01:08 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/19 16:08:29 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include <unistd.h>

//teste

bool ft_open_redirs(t_ms *ms, t_counters *c)
{
     if(ms->cmds[c->i].type == CMD)
        {
            if(ms->cmds[c->i].redirs[c->k].arg != NULL)
            {
                while(c->k < ft_count_redirs_cmd(&ms->cmds[c->i]))  
                {
                    if(ms->cmds[c->i].redirs[c->k].arg[0] == '$')
                        return(ft_error_var_start("ambiguous redirect", ms->cmds[c->i].redirs[c->k].arg, 1));
                    
                    if(ms->cmds[c->i].redirs[c->k].type == REDIR_OUT || ms->cmds[c->i].redirs[c->k].type == D_REDIR_OUT)
                        ms->cmds[c->i].out = open(ms->cmds[c->i].redirs[c->k].arg, O_CREAT | O_APPEND | O_WRONLY, 0777);
                    else if (ms->cmds[c->i].redirs[c->k].type == REDIR_IN)
                    {
                        if(open(ms->cmds[c->i].redirs[c->k].arg, O_RDONLY, 0777) != -1)
                            ms->cmds[c->i].in = open(ms->cmds[c->i].redirs[c->k].arg, O_RDONLY, 0777);
                        else
                        {
                            ms->cmds[c->i].err = true;
                            ft_error_var_start("No such file or directory", ms->cmds[c->i].redirs[c->k].arg, 1); 
                        }
                        if(!ms->cmds[c->i + 1].args)
                           return (false); 
                    }
                    else if (ms->cmds[c->i].redirs[c->k].type == HERE_DOC)
                        ft_is_heredoc(&ms->cmds[c->i], &ms->cmds[c->i].redirs[c->k]);
                    c->k++;
                }
               // if(ms->cmds[c->i].redirs[c->k - 1].arg[0] != '$')
                //{
                    if(ms->cmds[c->i].redirs[c->k - 1].type == REDIR_OUT)
                        ms->cmds[c->i].out = open(ms->cmds[c->i].redirs[c->k - 1].arg, O_CREAT | O_TRUNC | O_WRONLY, 0777);
                    else if(ms->cmds[c->i].redirs[c->k - 1].type == D_REDIR_OUT)
                        ms->cmds[c->i].out = open(ms->cmds[c->i].redirs[c->k - 1].arg, O_CREAT | O_APPEND | O_WRONLY, 0777);    
               // }
                // else
                // {
                //     ft_error_var_start("ambiguous redirect", ms->cmds[c->i].redirs[c->k - 1].arg, 1);
                //     return (false);
                // }
            }
        }
        return true;
    }
    

void ft_connect_pipes(t_ms *ms, t_counters *c)
{
    if(ms->cmds[c->i + 1].type == PIPE_LINE)
    {

        if(ms->cmds[c->i].out == 1)
        {
            ms->cmds[c->i].out = dup(ms->cmds[c->i + 1].fd[1]);
            close(ms->cmds[c->i + 1].fd[1]);
        }
        else
            close(ms->cmds[c->i + 1].fd[1]);    
    }		
    if(c->i > 0 && ms->cmds[c->i - 1].type == PIPE_LINE) 
    {
        if(ms->cmds[c->i].in == 0)
        {
            ms->cmds[c->i].in = dup(ms->cmds[c->i - 1].fd[0]);
            close(ms->cmds[c->i - 1].fd[0]);
        }
        else
        {
            close(ms->cmds[c->i - 1].fd[0]);
            close(ms->cmds[c->i - 1].fd[1]);
        }
    }
}


void ft_run_cmds(t_ms *ms)
{
    t_counters *c;

    c = ft_calloc(1, sizeof(t_counters ));
    ms->ms_env_array = ft_list_to_array(ms);
	ft_init_pipes(ms);
    while(ms->cmds[c->i].type)
    {
        c->k = 0;
        
        if(!ft_open_redirs(ms, c))
        {
            ft_free_counters(c);
            return ;          
            
        }
        ft_connect_pipes(ms, c);
        if(ms->cmds[c->i].type != PIPE_LINE)
        {
            if(ft_change_standard_in_out(&ms->cmds[c->i]))
            {
                ft_filter_cmd(ms, &ms->cmds[c->i]);
                ft_reset_fd_in_out(ms);
            }
        }
        c->i++;
    }
    ft_free_counters(c);
}



bool ft_change_standard_in_out(t_command *cmd)
{    
    if(cmd->out != 1)
	{
		if(dup2(cmd->out, STDOUT_FILENO) == -1)
		{
			printf("dup2 error!\n");
			return(false);
		}
		close(cmd->out);
	}
	if(cmd->in != 0)
	{
		if(dup2(cmd->in, STDIN_FILENO) == -1)
        {
            printf("dup2 error!\n");
            return(false);
        }
		else
            close(cmd->in);
	}
    return (true);
}

void ft_reset_fd_in_out(t_ms *ms)
{
    dup2(ms->std_out, STDOUT_FILENO);
    dup2(ms->std_in, STDIN_FILENO);
}
    
void ft_filter_cmd(t_ms *ms, t_command *cmd)
{
    char *tmp_list;
    
    if(!cmd->args[0])
        return ;
    if(ft_strcmp(cmd->args[0], "echo") == 0)
        ft_echo(cmd);
    else if(ft_strcmp(cmd->args[0], "cd") == 0)
        ft_cd(ms, cmd);
    else if(ft_strcmp(cmd->args[0], "env") == 0)
        ft_env(cmd, ms->ms_env);
    else if(ft_strcmp(cmd->args[0], "pwd") == 0)
    {
        tmp_list = ft_return_list_info(ms->ms_env, "PWD");
        printf("%s\n", tmp_list);
        ft_free(tmp_list);
    }
    else if(ft_strchr_vars(cmd->args[0], '='))
        ft_add_node_to_list(ms, ms->vars, cmd->args[0]);
    else if(ft_strcmp(cmd->args[0], "export") == 0)
        ft_export(ms, cmd);
    else if(ft_strcmp(cmd->args[0], "unset") == 0)
        ft_unset(ms);
    else if(ft_strcmp(cmd->args[0], "exit") == 0)
        ft_exit(ms);
    else if(!ft_is_executable(ms, cmd))
    {
        ft_reset_fd_in_out(ms);
        if(ft_is_absolute_path(cmd->args[0]))
            ft_error_var_start("No such file or directory", cmd->args[0], 2);
        else
            ft_printf("%s: command not found\n", cmd->args[0]);
        g_exit_status = 127;
    }
}

void ft_init_pipes(t_ms *ms)
{
    int i;

    i = 0;
    while(ms->cmds[i].type)
    {
        if(ms->cmds[i].type == PIPE_LINE)
            pipe(ms->cmds[i].fd);
		i++;
    }
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
        if(!read_content)
        {
            cmd->err = true;
            printf("\n");
            return ;
        }
        else
        {
            if(ft_strcmp(read_content, eof) == 0)
                break ;
            str = ft_strjoin(str, read_content);
            str = ft_strjoin(str, "\n");
        }
    }
    fd = open("temp.txt", O_WRONLY|O_CREAT|O_EXCL|O_TRUNC, 0600);
    fd2 = dup(fd);
    write(fd2, str, ft_strlen(str));
    close(fd2);
    open("temp.txt", O_RDONLY);
    close(fd);
    unlink("temp.txt");
    cmd->in = fd2;
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