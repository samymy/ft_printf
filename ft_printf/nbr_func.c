/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdubinki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 10:53:22 by vdubinki          #+#    #+#             */
/*   Updated: 2017/12/14 10:53:24 by vdubinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nbr_func.h"

void			ft_putsnbr(intmax_t n)
{
	char	*nbr;

	nbr = ft_sitoa(n);
	ft_putstr(nbr);
	free(nbr);
}

void			ft_putunbr(uintmax_t n)
{
	char	*nbr;

	nbr = ft_uitoa(n);
	ft_putstr(nbr);
	free(nbr);
}

size_t			ft_snbrlen(intmax_t n)
{
	size_t	len;

	len = 0;
	if (n < 0 || n == 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

size_t			ft_unbrlen(uintmax_t n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}
