/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_while_env.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 12:54:35 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/24 12:39:53 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_expand_while_env(t_lst *env, t_lst *vars, char *str)
{
	(void) vars;
	ft_free(str);
	return (ft_strdup(env->info));
}
