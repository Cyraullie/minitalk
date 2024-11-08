/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 11:21:14 by cgoldens          #+#    #+#             */
/*   Updated: 2024/10/02 15:31:44 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c = (c + 32);
	return (c);
}
/*
int	main(void)
{
	printf("%c", ft_tolower('h'));
	printf("%c", ft_tolower('P'));
}
*/
