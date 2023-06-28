/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 11:46:53 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/06/28 10:40:45 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void ft_cd(t_ms *ms, t_command *cmd)
{
    (void)ms;
    (void)cmd;
    char *pwd;
    char *oldpwd;
    
    pwd = malloc(sizeof(char) * 4096);
    oldpwd = malloc(sizeof(char) * 4096);
    oldpwd = getcwd(pwd, 4096);
    pwd = ft_strjoin(oldpwd, ft_strjoin("/", ft_strtrim(cmd->args[1], "/")));
    if(chdir(pwd) == 0)
    {
        ft_update_env(ms, "PWD", pwd);
        ft_update_env(ms, "OLDPWD", oldpwd);
    }
}

/**
 * 1. recebe o caminho absoluto ou relativo
 * 2. getcwd para saber o diretorio atual
 * 3. entra nesse diretorio
 * 
*/