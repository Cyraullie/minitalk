/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:29:43 by cgoldens          #+#    #+#             */
/*   Updated: 2024/10/10 11:45:19 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}
/*
int main(void)
{
    t_list *lst = NULL; 
    t_list *new1;
    t_list *new2;
 
    new1 = ft_lstnew("test");
    new2 = ft_lstnew("test42");

    ft_lstadd_front(&lst, new1); 
    ft_lstadd_front(&lst, new2); 

    t_list *current = lst;
    while (current)
    {
        printf("Content: %s\n", (char *)current->content);
        current = current->next;
    }

    return 0;
}
*/
