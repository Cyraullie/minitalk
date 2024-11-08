/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:14:38 by cgoldens          #+#    #+#             */
/*   Updated: 2024/10/01 15:21:13 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	cur;
	char	*data;

	cur = 0;
	data = (char *)b;
	while (cur < len)
	{
		data[cur] = c;
		cur++;
	}
	return (b);
}

/*
int	main(void)
{
	char test[5] = "salut";
	printf("%s", ft_memset(test, 'a', 6));
}
*/