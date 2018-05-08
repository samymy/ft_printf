/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_converter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdubinki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 11:38:49 by vdubinki          #+#    #+#             */
/*   Updated: 2017/12/14 11:38:51 by vdubinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "str_func.h"

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
				pn += write(1, "0x", 2);
				options->flags[4] = 0;
			}
			pn += ft_putfillers('0', options->min_width - len - flag);
		}
		else
			pn += ft_putfillers(' ', options->min_width - len - diff - flag);
	}
	if (options->flags[4])
		pn += write(1, "0x", 2);
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

int					p_converter(va_list ap,
								int length_modifier,
								t_options *options)
{
	char	*arg;
	int		len;
	int		pn;
	int		diff;
	int		flag;

	(void)length_modifier;
	options->flags[4] = 1;
	arg = ft_itoabase((unsigned long)va_arg(ap, void *), 16, 0);
	if (!ft_strcmp(arg, "0") && options->precision == 0)
		arg = "";
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
