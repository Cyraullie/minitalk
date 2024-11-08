/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 11:17:02 by cgoldens          #+#    #+#             */
/*   Updated: 2024/10/10 11:22:45 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*current;
	t_list	*tmp;

	if (!lst)
		return (NULL);
	tmp = lst;
	new = NULL;
	while (tmp)
	{
		current = ft_lstnew(f(tmp->content));
		if (!current)
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		ft_lstadd_back(&new, current);
		tmp = tmp->next;
	}
	return (new);
}
/*
void	*duplicate_content(void *content)
{
	return ft_strdup((char *)content);  // Duplique la chaîne de caractères
}

// Fonction de suppression utilisée pour ft_lstmap
void	del(void *content)
{
	free(content);  // Libère la mémoire du contenu
}

int main(void)
{
	t_list	*lst = NULL;
	t_list	*new1;
	t_list	*new2;
	t_list	*new3;
	t_list	*mapped_lst;

	new1 = ft_lstnew(ft_strdup("Element 1"));
	new2 = ft_lstnew(ft_strdup("Element 2"));
	new3 = ft_lstnew(ft_strdup("Element 3"));
	ft_lstadd_front(&lst, new3);
	ft_lstadd_front(&lst, new2);
	ft_lstadd_front(&lst, new1);
	mapped_lst = ft_lstmap(lst, duplicate_content, del);
	t_list	*current = mapped_lst;
	while (current)
	{
		printf("Mapped content: %s\n", (char *)current->content);
		current = current->next;
	}
	ft_lstclear(&lst, del);
	ft_lstclear(&mapped_lst, del);
	return 0;
}
*/
