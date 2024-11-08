/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:08:30 by cgoldens          #+#    #+#             */
/*   Updated: 2024/10/29 16:11:02 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbrlen_base10(unsigned	int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 10;
	}
	return (len);
}

static int	ft_putptr(uintptr_t num)
{
	int	res;

	res = 0;
	if (num >= 16)
	{
		res = ft_putptr(num / 16);
		res += ft_putptr(num % 16);
	}
	else
	{
		if (num <= 9)
			res = ft_printchar((num + '0'));
		else
			res = ft_printchar((num - 10 + 'a'));
	}
	if (res == -1)
		return (-1);
	return (res);
}

int	ft_printptr(unsigned long long ptr)
{
	int	print_length;
	int	res;

	print_length = 0;
	res = write(1, "0x", 2);
	if (res == -1)
		return (-1);
	print_length += res;
	if (ptr == 0)
	{
		res = ft_printchar('0');
		if (res == -1)
			return (-1);
		print_length += res;
	}
	else
	{
		res = ft_putptr(ptr);
		if (res == -1)
			return (-1);
		print_length += res;
	}
	return (print_length);
}

static char	*ft_uitoa(unsigned	int n)
{
	char	*num;
	int		l;

	l = ft_nbrlen_base10(n);
	num = (char *)malloc(sizeof(char) * (l + 1));
	if (!num)
		return (0);
	num[l] = '\0';
	while (n != 0)
	{
		num[l - 1] = n % 10 + 48;
		n = n / 10;
		l--;
	}
	return (num);
}

int	ft_printunsigned(unsigned	int n)
{
	int		l;
	char	*num;

	l = 0;
	if (n == 0)
		return (ft_printchar('0'));
	num = ft_uitoa(n);
	if (!num)
	{
		free(num);
		return (-1);
	}
	l = ft_printstr(num);
	free(num);
	return (l);
}
