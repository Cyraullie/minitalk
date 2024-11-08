/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 10:59:11 by cgoldens          #+#    #+#             */
/*   Updated: 2024/10/10 11:45:26 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next_lst;
	t_list	*current;

	if (!lst || !(*lst) || !del)
		return ;
	current = *lst;
	while (current != NULL)
	{
		next_lst = current->next;
		ft_lstdelone(current, del);
		current = next_lst;
	}
	*lst = NULL;
}
/*
void	del(void *content)
{
	free(content);
}

int	main(void)
{
	t_list	*lst;
	t_list	*new1;
	t_list	*new2;
	t_list	*new3;

	new1 = ft_lstnew(malloc(20));
	new2 = ft_lstnew(malloc(20));
	new3 = ft_lstnew(malloc(20));
	lst = NULL;
	ft_lstadd_front(&lst, new1);
	ft_lstadd_front(&lst, new2);
	ft_lstadd_front(&lst, new3);
	ft_lstclear(&lst, del);
	if (lst == NULL)
		printf("Liste vide\n");
	return (0);
}
*/
