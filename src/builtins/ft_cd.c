/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 11:46:53 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/10 15:39:31 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void ft_cd(t_ms *ms, t_command *cmd)
{
    char 	*pwd;
    char 	*oldpwd;
    char    *path;

    
    oldpwd = ft_return_list_info(ms->ms_env, "PWD");//pwd atual guardado no env
    if(!ft_arg_exist(cmd->args[1]))
        pwd =  ft_return_list_info(ms->ms_env, "HOME");
    else if(ft_is_absolute_path(cmd->args[1]))
		pwd = ft_strdup(cmd->args[1]);
    else
    {
        if(ft_strcmp(cmd->args[1], "..") == 0)
            pwd = ft_strtrim_end(oldpwd, '/');
        else
            pwd = ft_strjoin(oldpwd, ft_strjoin("/", ft_strtrim(cmd->args[1], "/")));  
        
    }
    if(chdir(pwd) == 0)//info
    {
        ft_update_list(ms->ms_env, "PWD", pwd); //full info
        ft_update_list(ms->ms_env, "OLDPWD", oldpwd); //full info
    }
    else
        printf("cd: no such file or directory: %s\n", cmd->args[1]);
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

/**
 * 1. recebe o caminho absoluto ou relativo
 * 2. getcwd para saber o diretorio atual
 * 3. entra nesse diretorio
 * 
*/