#include "../../../includes/minishell.h"

void	ft_print_list(t_env *list)
{
	while (list != NULL)
	{
		printf("Name: %s\nInfo: %s\nFull Info: %s\n", list->name, list->info, list->full_info);
		list = list->next;
		printf("\n");
	}
}

