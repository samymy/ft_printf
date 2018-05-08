/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_converter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdubinki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 11:29:05 by vdubinki          #+#    #+#             */
/*   Updated: 2017/12/14 11:29:07 by vdubinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "str_func.h"
#include "nbr_func.h"

static intmax_t		get_arg_by_type(va_list ap, int length_modifier)
{
	if (length_modifier == 0)
		return ((char)va_arg(ap, int));
	if (length_modifier == 1)
		return ((short)va_arg(ap, int));
	if (length_modifier == 2)
		return (va_arg(ap, long long));
	if (length_modifier == 3)
		return (va_arg(ap, long));
	if (length_modifier == 4 || length_modifier == 5)
		return (va_arg(ap, intmax_t));
	return (va_arg(ap, int));
}

static int			print_sign(int flag, t_options *options)
{
	int		pn;

	pn = 0;
	if (flag && options->flags[1])
	{
		pn += write(1, "+", 1);
		options->flags[1] = 0;
		options->flags[3] = 0;
	}
	if (flag && options->flags[3])
	{
		pn += write(1, " ", 1);
		options->flags[3] = 0;
	}
	if (options->flags[4])
	{
		write(1, "-", 1);
		options->flags[4] = 0;
	}
	return (pn);
}

static int			print_prefix(int len, int diff, int flag,
														t_options *options)
{
	int		pn;

	pn = 0;
	if (!options->flags[0])
	{
		if (options->flags[2] && options->precision == -1)
		{
			pn += print_sign(flag, options);
			pn += ft_putfillers('0', options->min_width - len - flag);
		}
		else
		{
			pn += ft_putfillers(' ', options->min_width - len - diff - flag);
			pn += print_sign(flag, options);
		}
	}
	pn += print_sign(flag, options);
	if (diff)
		pn += ft_putfillers('0', diff);
	return (pn);
}

static void			init(intmax_t *arg, int len, int *flag,
													t_options *options)
{
	options->flags[4] = 0;
	if (*arg >= 0 && (options->flags[1]
					|| (options->flags[3] && !options->flags[1])))
		*flag = 1;
	if (*arg < 0 && (options->flags[2] || options->precision > len))
	{
		*arg *= -1;
		options->flags[4] = 1;
	}
}

int					d_converter(va_list ap,
								int length_modifier,
								t_options *options)
{
	intmax_t	arg;
	int			len;
	int			pn;
	int			diff;
	int			flag;

	arg = get_arg_by_type(ap, length_modifier);
	len = (arg == 0 && options->precision == 0) ? 0 : ft_snbrlen(arg);
	pn = 0;
	diff = 0;
	flag = 0;
	if (options->precision >= len)
		diff = arg < 0 ? options->precision - len + 1
							: options->precision - len;
	init(&arg, len, &flag, options);
	pn += print_prefix(len, diff, flag, options);
	pn += print_sign(flag, options);
	if (!(arg == 0 && options->precision == 0))
		ft_putsnbr(arg);
	pn += len;
	if (options->flags[0])
		pn += ft_putfillers(' ', options->min_width - len - diff - flag);
	return (pn);
}
