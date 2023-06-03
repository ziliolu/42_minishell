
#include "../../../includes/minishell.h"

char	*ft_get_env_info(char *set)
{
	int 	i;
	
	i = 0;
	while (set[i] != '=')
		i++;
	return (ft_substr(set, i+1, ft_strlen(set)));
}