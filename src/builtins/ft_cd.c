/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 11:46:53 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/12 11:14:58 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool ft_is_home_path(char *str)
{
    if(!ft_arg_exist(str))
       return (true);
    if(ft_strcmp(str, "~") || ft_strcmp(str, "/"))
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
    path = NULL;
    tmp = NULL;
    
    if(ft_is_home_path(cmd->args[1]))
        pwd =  ft_return_list_info(ms->ms_env, "HOME");
    oldpwd = ft_return_list_info(ms->ms_env, "PWD");
    while(!ft_is_home_path(cmd->args[1]) && cmd->args[i])
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
    if(!ft_is_home_path(cmd->args[1]) && ft_is_absolute_path(cmd->args[1]))
		pwd = ft_strdup(path);
    else if(path)
    {
        if(ft_strcmp(path, "..") == 0)
            pwd = ft_strtrim_end(oldpwd, '/');
        else
            pwd = ft_strjoin(oldpwd, ft_strjoin("/", ft_strtrim(path, "/")));  
        
    }
    if((chdir(pwd) == 0 && ms->spaces_flag == 1 ) || ft_is_home_path(cmd->args[1]))
    {
        ft_update_list(ms->ms_env, "PWD", pwd);
        ft_update_list(ms->ms_env, "OLDPWD", oldpwd);
    }
    else if (path[0] == '$' && ms->spaces_flag == 1)
        chdir(ft_return_list_info(ms->ms_env, "HOME"));
    else if(ms->spaces_flag > 1)
        ft_error(ms, "cd: to many arguments", NULL);
    else
        ft_error(ms, "cd: no such file or directory %s\n", path);
    // free(pwd);
    // free(oldpwd);
}



char *ft_strtrim_end(char *str, char set)
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
    return (NULL); 
}
