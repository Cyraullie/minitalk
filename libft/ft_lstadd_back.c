/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:24:13 by cgoldens          #+#    #+#             */
/*   Updated: 2024/10/08 16:34:05 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	if (*lst)
		ft_lstlast(*lst)->next = new;
	else
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

    ft_lstadd_back(&lst, new1);
    ft_lstadd_back(&lst, new2);

    t_list *current = ft_lstlast(lst);
    printf("Content: %s\n", (char *)current->content);

    return 0;
}
*/
