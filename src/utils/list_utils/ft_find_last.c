/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:02:56 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/21 11:54:39 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

t_lst	*ft_find_last(t_lst *head)
{
	t_lst *list = head;
	while (list->next != NULL)
		list = list->next;
	return (list);
}