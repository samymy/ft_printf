/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_converter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdubinki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 11:49:52 by vdubinki          #+#    #+#             */
/*   Updated: 2017/12/14 11:49:54 by vdubinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "str_func.h"

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

static int			print_prefix(int len, int diff, int flag,
														t_options *options)
{
	int		pn;

	pn = 0;
	if (!options->flags[0])
	{
		if (options->flags[2] && options->precision == -1)
		{
			if (options->flags[4])
			{
				pn += write(1, "0b", 2);
				options->flags[4] = 0;
			}
			pn += ft_putfillers('0', options->min_width - len - flag);
		}
		else
			pn += ft_putfillers(' ', options->min_width - len - diff - flag);
	}
	if (options->flags[4])
		pn += write(1, "0b", 2);
	if (diff)
		pn += ft_putfillers('0', diff);
	return (pn);
}

static void			to_null(int *pn, int *diff, int *flag,
												t_options *options)
{
	*pn = 0;
	*diff = 0;
	*flag = 0;
	if (options->flags[4])
		*flag = 2;
}

int					b_converter(va_list ap,
								int length_modifier,
								t_options *options)
{
	char	*arg;
	int		len;
	int		pn;
	int		diff;
	int		flag;

	arg = ft_itoabase(get_arg_by_type(ap, length_modifier), 2, 0);
	if (!ft_strcmp(arg, "0"))
	{
		if (options->precision == 0)
			arg = "";
		options->flags[4] = 0;
	}
	len = ft_strlen(arg);
	to_null(&pn, &diff, &flag, options);
	if (options->precision > len)
		diff = options->precision - len;
	pn += print_prefix(len, diff, flag, options);
	pn += ft_nputstr(arg);
	if (options->flags[0])
		pn += ft_putfillers(' ', options->min_width - len - diff - flag);
	return (pn);
}
