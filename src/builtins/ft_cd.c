/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 11:46:53 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/06/28 17:29:03 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void ft_cd(t_ms *ms, t_command *cmd)
{
    (void)ms;
    (void)cmd;
    char *pwd;
    char *oldpwd;
    
    pwd = ft_calloc(1, sizeof(char));
    oldpwd = ft_calloc(1, sizeof(char));
    //oldpwd = getcwd(pwd, 4096);
    oldpwd = ft_return_env_info(ms, "PWD");//pwd atual guardado no env
    if(ft_strcmp(cmd->args[1], "..") == 0)
        pwd = ft_strtrim_end(oldpwd, '/');
    else
        pwd = ft_strjoin(oldpwd, ft_strjoin("/", ft_strtrim(cmd->args[1], "/")));  
        //pwd = ft_strjoin(oldpwd, ft_strjoin("/", cmd->args[1]));
    
    printf("oldpwd: %s\n", oldpwd);
    printf("pwd: %s\n", pwd);
    if(chdir(pwd) == 0)
    {
        ft_update_env(ms, "PWD", pwd);
        ft_update_env(ms, "OLDPWD", oldpwd);
    }
    else
        printf("cd: no such file or directory: %s\n", cmd->args[1]);
    //free(pwd);
    //free(oldpwd);
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