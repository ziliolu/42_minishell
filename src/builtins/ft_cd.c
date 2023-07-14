/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 11:46:53 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/13 19:51:17 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool ft_is_home_path(char *str)
{
    if(!ft_arg_exist(str))
       return (true);
    if(ft_strcmp(str, "~") == 0 || ft_strcmp(str, "/") == 0
        || (ft_strcmp(str, "~/") == 0))
        return (true);
    return (false);
}

void ft_cd(t_ms *ms, t_command *cmd)
{
    char 	*pwd;
    char 	*oldpwd;
    char    *path;
    char *tmp;
    int i;
    
    i = 1;
    pwd = NULL;
    path = NULL;
    tmp = NULL;
    
    oldpwd = ft_return_list_info(ms->ms_env, "PWD");
    if(ft_is_home_path(cmd->args[1]))
        pwd =  ft_return_list_info(ms->ms_env, "HOME");
    else if(ft_strcmp(cmd->args[1], "-") == 0)
    {
        pwd = ft_return_list_info(ms->ms_env, "OLDPWD");
        printf("%s\n", pwd);
    }
    else if(ft_strcmp(cmd->args[1], ".") == 0)
        return ;
    while(!pwd && !ft_is_home_path(cmd->args[1]) && cmd->args[i])
    {
        if(!tmp)
        {
            tmp = ft_strdup(cmd->args[i]);
            path = ft_strdup(cmd->args[i]);
        }
        else
        {
            if(path)
                free(path);
            path = ft_strjoin(tmp, cmd->args[i]);
            if(tmp)
                free(tmp);
            tmp = ft_strdup(path);
        }
        i++;
    }
    if(path)
        path = ft_strtrim_end(path, '/');
    if(!pwd && !ft_is_home_path(cmd->args[1]) && ft_is_absolute_path(cmd->args[1]))
    {
        if(cmd->args[1][0] == '~' && cmd->args[1][1] == '/') 
            pwd = ft_strjoin(ft_return_list_info(ms->ms_env, "HOME"), ft_strtrim(path, "~"));
        else
    		pwd = ft_strdup(path);
    }
    else if(path)
    {
        if(ft_strcmp(path, "..") == 0)
            pwd = ft_strtrim_end_quote(oldpwd, '/');
        else
            pwd = ft_strjoin(oldpwd, ft_strjoin("/", ft_strtrim(path, "/")));  
        
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
    // free(pwd);
    // free(oldpwd);
}



char *ft_strtrim_end(char *str, char set)
{
    int i;
    char *new_str;

    i = ft_strlen(str);
    if(str[i] == set)
    {
        new_str = ft_calloc(i - 1, sizeof(char));
        ft_strlcpy(new_str, str, i - 1);
        return(new_str);
    }
    return (str); 
}

char *ft_strtrim_end_quote(char *str, char set)
{
    int i;
    int j;
    char *new_str;

    i = ft_strlen(str);
    while(i >= 0)
    {
        if(str[i] == set)
        {
            j = i;
            new_str = ft_calloc(j + 1, sizeof(char));
            ft_strlcpy(new_str, str, j + 1);
            return(new_str);
        }
        i--;
    }
    return (str); 
}
