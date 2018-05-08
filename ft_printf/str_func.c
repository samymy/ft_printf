/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdubinki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 10:30:40 by vdubinki          #+#    #+#             */
/*   Updated: 2017/12/14 10:30:42 by vdubinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str_func.h"

void			ft_swap(char *s1, char *s2)
{
	char	tmp;

	tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}

int				ft_nputstr(char *str)
{
	return (write(1, str, ft_strlen(str)));
}

int				ft_putfillers(char filler, int n)
{
	int		pn;

	if (n < 0 || n == 0)
		return (0);
	pn = 0;
	while (n)
	{
		pn += write(1, &filler, 1);
		n--;
	}
	return (pn);
}

char			*ft_itoabase(uintmax_t nbr, int base, int uppercase)
{
	static char		buffer[50];
	char			*ptr;
	int				rem;

	ptr = &buffer[49];
	*ptr = '\0';
	if (nbr == 0)
		*--ptr = '0';
	while (nbr != 0)
	{
		rem = nbr % base;
		*--ptr = rem >= 10 ? rem - 10 + 'a' - (32 * uppercase) : rem + '0';
		nbr /= base;
	}
	return (ptr);
}

int				ft_natoi(const char *str)
{
	int		number;

	number = 0;
	while (*str >= '0' && *str <= '9')
		number = number * 10 + (*str++ - '0');
	return (number);
}
