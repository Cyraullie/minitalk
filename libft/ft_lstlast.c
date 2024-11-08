/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:07:40 by cgoldens          #+#    #+#             */
/*   Updated: 2024/10/10 11:45:50 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}
/*
int     main(void)
{
    t_list *lst = NULL;
    t_list *new1;
    t_list *new2;
    t_list *new3;

    new1 = ft_lstnew("element 2");
    new2 = ft_lstnew("element 1");
    new3 = ft_lstnew("element 3");

    ft_lstadd_front(&lst, new1);
    ft_lstadd_front(&lst, new2);
    ft_lstadd_front(&lst, new3);
    
    t_list *tmp;

    tmp = ft_lstlast(lst);

    printf("le dernier element de la liste est : %s\n", (char *)tmp->content);

    return 0;
}
*/
