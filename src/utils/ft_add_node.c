#include "../../includes/minishell.h"

void	ft_add_node(t_env **header, char *str)
{
	t_env	*new;
	t_env	*last;

	new = ft_new_node(str);
	last = ft_find_last(*header);
	last->next = new;
}