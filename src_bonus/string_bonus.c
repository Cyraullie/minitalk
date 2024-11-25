/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:43:00 by cgoldens          #+#    #+#             */
/*   Updated: 2024/11/25 14:20:13 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

char	*ft_charcat(char *s, unsigned char c)
{
	char	*tmp;
	int		len;

	len = ft_strlen(s);
	tmp = malloc(len + 2);
	if (!tmp)
		return (NULL);
	ft_strlcpy(tmp, s, len + 1);
	tmp[len] = c;
	tmp[len + 1] = '\0';
	free(s);
	return (tmp);
}

int	get_all_c(unsigned char c)
{
	static char	*str = NULL;

	if (!str)
	{
		str = malloc(1);
		if (!str)
			exit(EXIT_FAILURE);
		str[0] = '\0';
	}
	str = ft_charcat(str, c);
	if (c == '\0')
	{
		printf("%s\n", str);
		free(str);
		str = NULL;
	}
	return (0);
}

void	send_endchar(pid_t sv_pid)
{
	unsigned char	c;
	int				nbr_bits;

	c = '\0';
	nbr_bits = 8;
	while (nbr_bits--)
	{
		if (c & 0b10000000)
			kill(sv_pid, SIGUSR1);
		else
			kill(sv_pid, SIGUSR2);
		usleep(50);
		c <<= 1;
	}
}
