
#include "../../../includes/minishell.h"

char	*ft_get_env_name(char *set)
{
	int 	i;
	
	i = 0;
	while (set[i] != '=')
		i++;
	return (ft_substr(set, 0, i));
}