/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 11:46:53 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/06/27 17:11:29 by lpicoli-         ###   ########.fr       */
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
        printf("path: %s\n", path);
        ft_update_env(ms, "PWD", path);
        ft_print_env(ms);
        //ft_print_env_info()
    }
    //ft_print_env(*ms->ms_env);
}

/**
 * 1. recebe o caminho absoluto ou relativo
 * 2. getcwd para saber o diretorio atual
 * 3. entra nesse diretorio
 * 
*/