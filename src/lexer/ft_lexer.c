/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:44:30 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/12 16:01:45 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void ft_lexer(t_ms *ms, char *str)
{
    enum e_status status;
    t_elem **elem_head;
    // char *str_tmp;
    int squote_flag;
    int dquote_flag;
    int i;
    //int index;
    
    (void) ms;
    status = GENERAL; //default
    squote_flag = 0;
    dquote_flag = 0;
    elem_head = (t_elem **)ft_calloc(1, sizeof(t_elem *));
    i = 0;
    // if(ft_check_syntax_error())
    //     return (ft_error());
    
    while(str[i])
    {
        // str_tmp = NULL;
        if(str[i] == WHITE_SPACE && status != GENERAL)
            ft_add_new_elem(elem_head, ft_new_elem(str + i, 1, WHITE_SPACE, status));
        else if(str[i] == SINGLE_QUOTE)
        {
            if(squote_flag == 0 && dquote_flag == 0) //PRIMEIRA PLICA
            {
                squote_flag = 1;
                status = GENERAL;
                ft_add_new_elem(elem_head, ft_new_elem(str + i, 1, SINGLE_QUOTE, status));
                status = IN_SQUOTE;
            } 
            else if(squote_flag == 1 && dquote_flag == 0) //ULTIMA plica
            {
                squote_flag = 0;
                status = GENERAL;
                ft_add_new_elem(elem_head, ft_new_elem(str + i, 1, SINGLE_QUOTE, status));
            }
            else
                ft_add_new_elem(elem_head, ft_new_elem(str + i, 1, SINGLE_QUOTE, status));
        }
        else if(str[i] == DOUBLE_QUOTE)
        {
            if(dquote_flag == 0 && squote_flag == 0)
            {
                dquote_flag = 1;
                status = GENERAL;
                ft_add_new_elem(elem_head, ft_new_elem(str + i, 1, DOUBLE_QUOTE, status));
                status = IN_DQUOTE;
            }
            else if(dquote_flag == 1 && squote_flag == 0)
            {
                dquote_flag = 0;
                status = GENERAL;
                ft_add_new_elem(elem_head, ft_new_elem(str + i, 1, DOUBLE_QUOTE, status));
            }
            else
                ft_add_new_elem(elem_head, ft_new_elem(str + i, 1, DOUBLE_QUOTE, status));
        }
        else if(str[i] == PIPE_LINE)
            ft_add_new_elem(elem_head, ft_new_elem(str + i, 1, PIPE_LINE, status));
        else if(str[i] == REDIR_IN)
        {
            if (str[i + 1] == REDIR_IN)
            {
                ft_add_new_elem(elem_head, ft_new_elem(str + i, 2, HERE_DOC, status));
                i++;
            }
            else  
                ft_add_new_elem(elem_head, ft_new_elem(str + i, 1, REDIR_IN, status));
        }
        else if(str[i] == REDIR_OUT)
        {
            if(str[i + 1] == REDIR_OUT)
            {
                ft_add_new_elem(elem_head, ft_new_elem(str + i, 2, D_REDIR_OUT, status));
                i++;
            }
            else    
                ft_add_new_elem(elem_head, ft_new_elem(str + i, 1, REDIR_OUT, status));
        }
        else if(str[i] == WHITE_SPACE)
            ft_add_new_elem(elem_head, ft_new_elem(str + i, 1, WHITE_SPACE, status));
		else
        {
            if(str[i] == '$' && (ft_is_valid_character(str[i + 1]) || str[i + 1] == '?'))
            {
                // index = i;
                // while(str[index] && str[index] != WHITE_SPACE)
                // {
                //     if(!str_tmp)
                //         str_tmp = ft_strndup(str + index, 1);
                //     else
                //         str_tmp = ft_strjoin(str_tmp, ft_strndup(str + index, 1));
                //     if((ft_is_already_in_list(ft_strtrim(str_tmp, "$"), ms->ms_env)) || ft_is_already_in_list(ft_strtrim(str_tmp, "$"), *ms->vars))
                //     {
                //         ft_add_new_elem(elem_head, ft_new_elem(str + i, index - i + 1, ENV, status));
                //         i = i + (index - i);
                //         break ;
                //     }
                //     index++;
                //     //i++;
                // }
                // if(i < index)
                // {
                //     ft_add_new_elem(elem_head, ft_new_elem(str + i, ft_count_char_env(str + i), ENV, status));
                //     i = i + ft_count_char_env(str + i) - 1; 
                // } 
                ft_add_new_elem(elem_head, ft_new_elem(str + i, ft_count_char_env(str + i), ENV, status));
                i = i + ft_count_char_env(str + i) - 1; 
            }
            else if(str[i] == '$' && !str[i + 1])
            {
                ft_add_new_elem(elem_head, ft_new_elem(str + i, 1, WORD, status));
                i++;
            }
			else
            {
                // if(str[i - 1] && str[i - 1] == '$')
                // {ccvvv

                //     i--;
                //     ft_add_new_elem(elem_head, ft_new_eelem(str + i, ft_count_char_env(str + i), WORD, status));
                //     i = i + ft_count_char_env(str + i);
                                    
                // }
                // else
                //{
                    ft_add_new_elem(elem_head, ft_new_elem(str + i, ft_count_char(str + i), WORD, status));
                    i = i + ft_count_char(str + i) - 1;        
                //}
        	}
		}
        if(!str[i + 1])
            break;
        i++;
    }
	ms->lexed_list = elem_head;

}

int ft_count_char(char *str)
{ 
    int i;
    i = 0;
    while(str[i] != WHITE_SPACE && str[i] != PIPE_LINE && str[i] != SINGLE_QUOTE && str[i] != DOUBLE_QUOTE && str[i] != '$' && str[i] != '\0')
    {
		i++;
	}
	return (i);
}

int ft_count_char_env(char *str)
{ 
    int i;
    i = 0;
	
	i++;
    while(str[i] != WHITE_SPACE && str[i] != PIPE_LINE && str[i] != SINGLE_QUOTE && str[i] != DOUBLE_QUOTE && ft_valid_env(str[i]) && str[i] != '\0')
    {
		i++;
	}
	return (i);
}
int	ft_valid_env(char c)
{
	if ((c >= 65 && c <= 90 ) || (c == 95) || (c >= 97 && c <= 122))
		return (1);
	return (0);
}
