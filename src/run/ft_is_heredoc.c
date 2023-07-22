/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_cmds copy 8.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 10:01:08 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/22 21:30:33 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_is_heredoc(t_command *cmd, t_redirect *redir)
{
	char	*eof;
	char	*str;
	int		fd;
	int		fd2;
	char	*read_content;
	char	*prompt;

	(void) cmd;
	prompt = "> ";
	eof = redir->arg;
	str = ft_calloc(1, sizeof(char));
	read_content = ft_calloc(1, sizeof(char));
	while (ft_strcmp(read_content, eof) != 0)
	{
		read_content = readline(prompt);
		if (!read_content)
		{
			cmd->err = true;
			printf("\n");
			return ;
		}
		else
		{
			if (ft_strcmp(read_content, eof) == 0)
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
