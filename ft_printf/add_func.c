/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdubinki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 13:29:12 by vdubinki          #+#    #+#             */
/*   Updated: 2017/12/22 13:29:13 by vdubinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "add_func.h"

static char		*ft_strrev(char *str)
{
	size_t	start;
	size_t	end;

	start = 0;
	end = ft_strlen(str);
	while (start < end)
		ft_swap(&str[start++], &str[--end]);
	return (str);
}

static size_t	get_ssize(intmax_t n, int *negative)
{
	size_t	size;

	if (n == 0)
		return (1);
	size = 0;
	*negative = 0;
	if (n < 0)
	{
		*negative = 1;
		size++;
		n = -n;
	}
	while (n != 0)
	{
		size++;
		n /= 10;
	}
	return (size);
}

char			*ft_sitoa(intmax_t n)
{
	char	*result;
	size_t	index;
	int		negative;

	if (n == -9223372036854775807 - 1)
		return (ft_strdup("-9223372036854775808"));
	index = 0;
	negative = 0;
	result = (char *)malloc(get_ssize(n, &negative) + 1);
	if (result == NULL)
		return (NULL);
	if (n == 0)
		result[index++] = '0';
	if (n < 0)
		n = -n;
	while (n != 0)
	{
		result[index++] = n % 10 + '0';
		n /= 10;
	}
	if (negative)
		result[index++] = '-';
	result[index] = '\0';
	return (ft_strrev(result));
}

static size_t	get_usize(uintmax_t n)
{
	size_t	size;

	if (n == 0)
		return (1);
	size = 0;
	while (n != 0)
	{
		size++;
		n /= 10;
	}
	return (size);
}

char			*ft_uitoa(uintmax_t n)
{
	char	*result;
	size_t	index;

	index = 0;
	result = (char *)malloc(get_usize(n) + 1);
	if (result == NULL)
		return (NULL);
	if (n == 0)
		result[index++] = '0';
	while (n != 0)
	{
		result[index++] = n % 10 + '0';
		n /= 10;
	}
	result[index] = '\0';
	return (ft_strrev(result));
}
