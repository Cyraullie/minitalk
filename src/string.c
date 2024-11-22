/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:43:00 by cgoldens          #+#    #+#             */
/*   Updated: 2024/11/22 15:07:17 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*ft_charcat(char *s, unsigned char c)
{
	char	*tmp;
	int		len;

	len = ft_strlen(s);
	tmp = malloc(len + 2);
	if (!tmp)
		return (NULL);
	ft_strlcpy(tmp, s, len);
	printf("len_%ld\n", ft_strlen(tmp));
	printf("text_%s_%c\n", tmp, c);
	tmp[len + 1] = c;
	tmp[len + 2] = '\0';
	free(s);
	return (tmp);
}

int	get_all_c(unsigned char c)
{
	static char	*str;

	if (!str)
	{
		str = malloc(1);
		str[0] = c;
	}
	str = ft_charcat(str, c);
	return (0);
}