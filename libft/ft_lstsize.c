/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 15:40:01 by cgoldens          #+#    #+#             */
/*   Updated: 2024/10/10 11:46:03 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		count;
	t_list	*tmp;

	count = 0;
	tmp = lst;
	while (tmp != NULL)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}
/*
int	main(void)
{
    t_list *lst = NULL;
    t_list *new1;
    t_list *new2;
    t_list *new3;

    new1 = ft_lstnew("element 1");
    new2 = ft_lstnew("element 2");
    new3 = ft_lstnew("element 3");

    ft_lstadd_front(&lst, new1);
    ft_lstadd_front(&lst, new2);
    ft_lstadd_front(&lst, new3);

    printf("Taille de la liste : %d\n", ft_lstsize(lst));

    return 0;
}
*/
