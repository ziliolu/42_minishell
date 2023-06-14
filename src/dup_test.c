/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 13:00:04 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/06/14 15:56:02 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// int main(int argc, char **argv, char **env)
// {
//     char *command[] = {"mkdir", "testepasta"};
//     char *bin = command[0];

//     int redirect = open("testando.text", O_CREAT | O_TRUNC | O_WRONLY);
//     dup2(redirect, STDOUT_FILENO);

//     if(execve("/usr/bin/mkdir", command, env) == -1)
//         printf("error!");
//     else
//         printf("done!");
// }