/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 13:03:59 by cgoldens          #+#    #+#             */
/*   Updated: 2024/10/29 16:10:58 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printchar(int c)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}

int	ft_formats(va_list args, const char format)
{
	int	l;
	int	res;

	l = 0;
	res = 0;
	if (format == '%')
		res = ft_printchar('%');
	else if (format == 's')
		res = ft_printstr(va_arg(args, char *));
	else if (format == 'c')
		res = ft_printchar(va_arg(args, int));
	else if (format == 'd' || format == 'i')
		res = ft_printnbr(va_arg(args, int));
	else if (format == 'x' || format == 'X')
		res = ft_printhex(va_arg(args, unsigned int), format);
	else if (format == 'p')
		res = ft_printptr(va_arg(args, unsigned long long));
	else if (format == 'u')
		res = ft_printunsigned(va_arg(args, unsigned int));
	if (res == -1)
		return (res);
	l += res;
	return (l);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	va_list	args;
	int		l;
	int		res;

	i = 0;
	l = 0;
	res = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			res = ft_formats(args, s[i + 1]);
			i++;
		}
		else
			res = ft_printchar(s[i]);
		if (res == -1)
			return (res);
		l += res;
		i++;
	}
	va_end(args);
	return (l);
}
/*
int	main(void)
{
	//ft_printf("%c", 't');
//	printf("\n");
//	ft_printf("%s", "test");
//	printf("\n");
//	ft_printf("%%");
	//ft_printf("\001\002\007\v\010\f\r\n");
	//printf("%d", ft_printstr((char *)NULL));
	//ft_printstr((char *)NULL);
	//ft_printf("%s", (char *)NULL);
	//printf("%d", ft_printf("\001\002\007\v\010\f\r\n"));
//	printf("\n");
//	ft_printf("%i", 142);
//	printf("\n");
//	ft_printf("%x", 422);
//	printf("\n");
//	ft_printf("%X", 422);
//	printf("\n");
//	ft_printf("%X", 0);
//	printf("\n");
//	ft_printf("%p", "");
//	printf("\n");
//	ft_printf("%u", 5654651);
//	printf("\n");
//	ft_printf("__");
//	ft_printf("\n");
//	ft_printf("__test");
}
*/