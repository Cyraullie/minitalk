/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 14:25:28 by cgoldens          #+#    #+#             */
/*   Updated: 2024/10/29 16:11:06 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_putstr(char *s)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (s[i])
	{
		if (ft_printchar(s[i]) == -1)
			return (-1);
		i++;
		res++;
	}
	return (res);
}

int	ft_printstr(char *s)
{
	if (s == NULL)
		return (ft_putstr("(null)"));
	return (ft_putstr(s));
}

int	ft_printnbr(int n)
{
	int		len;
	char	*num;

	len = 0;
	num = ft_itoa(n);
	if (!num)
	{
		free(num);
		return (-1);
	}
	len = ft_printstr(num);
	free(num);
	return (len);
}

static int	ft_puthex(unsigned	int n, const	char f)
{
	int	res;

	res = 0;
	if (n >= 16)
	{
		res = ft_puthex(n / 16, f);
		if (res == -1)
			return (-1);
		res += ft_puthex(n % 16, f);
	}
	else
	{
		if (n <= 9)
			res = ft_printchar(n + '0');
		else
		{
			if (f == 'x')
				res = ft_printchar(n - 10 + 'a');
			else if (f == 'X')
				res = ft_printchar(n - 10 + 'A');
		}
		if (res == -1)
			return (-1);
	}
	return (res);
}

int	ft_printhex(unsigned	int n, const	char f)
{
	if (!n)
		return (ft_printchar('0'));
	return (ft_puthex(n, f));
}
