/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 11:46:53 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/06/28 10:31:56 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void ft_cd(t_ms *ms, t_command *cmd)
{
    char *path;
    (void)ms;
    (void)cmd;
    char *pwd;
    
    pwd = malloc(sizeof(char) * 4096);
    path = ft_strjoin(getcwd(pwd, 4096), "/");
    path = ft_strjoin(path, cmd->args[1]);
    if(chdir(path) == 0)
    {
        ft_update_env(ms, "PWD", path);
    }
}

/**
 * 1. recebe o caminho absoluto ou relativo
 * 2. getcwd para saber o diretorio atual
 * 3. entra nesse diretorio
 * 
*/