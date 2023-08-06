/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getcwd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 10:51:34 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/08/06 05:19:19 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char	*ft_getcwd(void)
{
	char	buf[256];
	char	*tmp;

	tmp = ft_strdup(getcwd(buf, sizeof(buf)));
	return (tmp);
}
