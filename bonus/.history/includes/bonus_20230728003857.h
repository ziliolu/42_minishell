/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:36:28 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/28 00:38:57 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H
# include "../lib/libft/libft.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/types.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h>
# include <limits.h>

typedef struct s_op_or
{
	int	i;
	int	or;
	int	arg_size;
}

typedef struct s_or
{
	int	i;
	int	or;
	int	arg_size;
}

#endif