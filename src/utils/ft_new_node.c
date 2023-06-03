#include "../../includes/minishell.h"

t_env	*ft_new_node(char *str)
{
	t_env	*var;

	var = (t_env *)malloc(sizeof(t_env));
	if (var)
	{
		var->name = ft_get_env_name(str);
		var->info = ft_get_env_info(str);
		var->full_info = str;
		var->next = NULL;
		return (var);
	}
	free (var);
	return (NULL);
}