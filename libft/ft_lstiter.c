/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 11:08:40 by cgoldens          #+#    #+#             */
/*   Updated: 2024/10/10 11:45:43 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst && f)
	{
		f(lst->content);
		lst = lst->next;
	}
}
/*
void	print_content(void *content)
{
	printf("Contenu : %s\n", (char *)content);
}

int	main(void)
{
	t_list	*lst = NULL;
	t_list	*new1;
	t_list	*new2;
	t_list	*new3;

	new1 = ft_lstnew("Element 1");
	new2 = ft_lstnew("Element 2");
	new3 = ft_lstnew("Element 3");

	ft_lstadd_front(&lst, new3);
	ft_lstadd_front(&lst, new2);
	ft_lstadd_front(&lst, new1);

	ft_lstiter(lst, print_content);

	return (0);
}
*/