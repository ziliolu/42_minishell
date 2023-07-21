/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 11:46:53 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/21 16:28:03 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void ft_cd(t_ms *ms, t_command *cmd)
{
    char 	*pwd;
    char 	*oldpwd;
    char    *path;
    char    *tmp;
    char    *tmp_path;
    char    *tmp_path_w_slash;
    int i;
    
    i = 1;
    pwd = NULL;
    path = NULL;
    tmp = NULL;
    
    if(ft_is_home_path(cmd->args[1]))
        pwd =  ft_return_list_info(ms->ms_env, "HOME");
    else if(ft_strcmp(cmd->args[1], "-") == 0)
    {
        pwd = ft_return_list_info(ms->ms_env, "OLDPWD");
        printf("%s\n", pwd);
    }
    else if(ft_strcmp(cmd->args[1], ".") == 0)
        return ;
    oldpwd = ft_return_list_info(ms->ms_env, "PWD");
    while(!pwd && !ft_is_home_path(cmd->args[1]) && cmd->args[i])
    {
        if(!tmp)
        {
            tmp = ft_strdup(cmd->args[i]);
            ft_free(path);
            path = ft_strdup(cmd->args[i]);
        }
        else
        {
            ft_free(path);
            path = ft_strjoin(tmp, cmd->args[i]);
            ft_free(tmp);
            tmp = ft_strdup(path);
        }
        i++;
    }
    if(path)
    {
        ft_free(path);
        path = ft_strtrim_end(tmp, '/');
        //free(tmp);
    }
    ft_free(tmp);
    if(!pwd && !ft_is_home_path(cmd->args[1]) && ft_is_absolute_path(cmd->args[1]))
    {
        if(cmd->args[1][0] == '~' && cmd->args[1][1] == '/') 
            pwd = ft_strjoin(ft_return_list_info(ms->ms_env, "HOME"), ft_strtrim(path, "~"));
        else
    		pwd = ft_strdup(path);
    }
    else if(path)
    {
        if(pwd)
            ft_free(pwd);
        if(ft_strcmp(path, "..") == 0)
            pwd = ft_strtrim_end_quote(oldpwd, '/');
        else
        {
            tmp_path = ft_strtrim(path, "/");
            tmp_path_w_slash = ft_strjoin("/", tmp_path);
            pwd = ft_strjoin(oldpwd, tmp_path_w_slash); 
            ft_free(tmp_path);
            ft_free(tmp_path_w_slash);
        }
        
    }
    if(chdir(pwd) == 0 && ((ms->spaces_flag <= 1 ) || ft_is_home_path(cmd->args[1])))
    {
        ft_update_list(ms->ms_env, "PWD", pwd);
        ft_update_list(ms->ms_env, "OLDPWD", oldpwd);
    }
    else if (path[0] == '$' && ms->spaces_flag == 1)
        chdir(ft_return_list_info(ms->ms_env, "HOME"));
    else if(ms->spaces_flag > 1)
        ft_error(ms, "cd: too many arguments", NULL);
    else
        ft_printf("minishell: cd: %s: no such file or directory\n", path);
    free(path);
    free(oldpwd);
    free(pwd);
}






