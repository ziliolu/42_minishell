#include "../../includes/minishell.h"

void	ft_add_node(t_lst **header, char *str)
{
	t_lst	*new;
	t_lst	*last;

	new = ft_new_node(str);
	if(*header == NULL)
    {
        *header = new;
		return ;
    }
	last = ft_find_last(*header);
	last->next = new;
}

#include "../../includes/minishell.h"

void	ft_add_export_node(t_lst **header, char *str)
{
	t_lst	*new;
	//t_lst	*last;
	t_lst 	*tmp;

	new = ft_new_node(str);
	if(*header == NULL)
    {
        *header = new;
		return ;
    }
	new->next = ft_find_last(*header);			 //novo passa a apontar para o último
	tmp = ft_find_second_to_last(header); //guarda o penúltimo nó
	tmp->next = new; 			//penúltimo passa a apontar para o novo nó
	//last->next = NULL;
}

t_lst *ft_find_second_to_last(t_lst **head)
{
	t_lst *list;

	list = *head;
	while(list->next)
	{
		if(ft_strcmp(list->next->name, "_") == 0)
			return(list);
		list = list->next;
	}
	return (NULL);
}
