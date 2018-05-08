/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_converter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdubinki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 11:35:33 by vdubinki          #+#    #+#             */
/*   Updated: 2017/12/14 11:35:35 by vdubinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "str_func.h"
#include "nbr_func.h"

static uintmax_t	get_arg_by_type(va_list ap, int length_modifier)
{
	if (length_modifier == 0)
		return ((unsigned char)va_arg(ap, unsigned));
	if (length_modifier == 1)
		return ((unsigned short)va_arg(ap, unsigned));
	if (length_modifier == 2)
		return (va_arg(ap, unsigned long long));
	if (length_modifier == 3)
		return (va_arg(ap, unsigned long));
	if (length_modifier == 4)
		return (va_arg(ap, uintmax_t));
	if (length_modifier == 5)
		return (va_arg(ap, size_t));
	return (va_arg(ap, unsigned));
}

static int			print_prefix(int len, int diff, t_options *options)
{
	int		pn;

	pn = 0;
	if (!options->flags[0])
	{
		if (options->flags[2] && options->precision == -1)
			pn += ft_putfillers('0', options->min_width - len);
		else
			pn += ft_putfillers(' ', options->min_width - len - diff);
	}
	if (diff)
		pn += ft_putfillers('0', diff);
	return (pn);
}

int					u_converter(va_list ap,
								int length_modifier,
								t_options *options)
{
	uintmax_t	arg;
	int			len;
	int			pn;
	int			diff;

	arg = get_arg_by_type(ap, length_modifier);
	len = (arg == 0 && options->precision == 0) ? 0 : ft_unbrlen(arg);
	pn = 0;
	diff = 0;
	if (options->precision > len)
		diff = options->precision - len;
	pn += print_prefix(len, diff, options);
	if (!(arg == 0 && options->precision == 0))
		ft_putunbr(arg);
	pn += len;
	if (options->flags[0])
		pn += ft_putfillers(' ', options->min_width - len - diff);
	return (pn);
}
