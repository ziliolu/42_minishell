#include "../../includes/minishell.h"

t_env	*ft_find_last(t_env *list)
{
	while (list->next != NULL)
		list = list->next;
	return (list);
}