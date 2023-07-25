/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_elem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:50:18 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/25 11:58:59 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_elem	*ft_new_elem(char *str, int len, \
	enum e_token type, enum e_status *status)
	{
	t_elem	*node;
	char	*str_tmp;

	str_tmp = ft_strndup(str, len);
	node = (t_elem *)ft_calloc(1, sizeof(t_elem));
	if (node)
	{
		if (ft_strrchr(str_tmp, '\\') && *status == GENERAL)
			node->data = ft_chartrim_wo_dquotes(str_tmp, '\\');
		else if (ft_strrchr(str_tmp, '\\') && *status == IN_DQUOTE)
			node->data = ft_chartrim_w_dquotes(str_tmp, '\\');
		else
			node->data = ft_strdup(str_tmp);
		node->len = ft_strlen(node->data);
		node->next = NULL;
		node->status = *status;
		node->type = type;
		free(str_tmp);
		return (node);
	}
	free (node);
	return (NULL);
}
