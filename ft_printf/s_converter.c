/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_converter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdubinki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 11:20:50 by vdubinki          #+#    #+#             */
/*   Updated: 2017/12/14 11:20:52 by vdubinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "str_func.h"

static int		print_prefix(int len, t_options *options)
{
	if (!options->flags[0])
	{
		if (options->flags[2])
			return (ft_putfillers('0', options->min_width - len));
		else
			return (ft_putfillers(' ', options->min_width - len));
	}
	return (0);
}

int				s_converter(va_list ap, int length_modifier, t_options *options)
{
	char	*arg;
	int		len;
	int		pn;
	char	tmp[options->precision + 1];

	if (length_modifier == 3)
		return (suc_converter(ap, -1, options));
	arg = va_arg(ap, char *);
	if (!arg)
		arg = "(null)";
	len = ft_strlen(arg);
	pn = 0;
	if (options->precision != -1)
		if (options->precision < len)
		{
			ft_strncpy(&tmp[0], arg, options->precision);
			tmp[options->precision] = '\0';
			arg = &tmp[0];
			len = ft_strlen(arg);
		}
	pn += print_prefix(len, options);
	pn += ft_nputstr(arg);
	if (options->flags[0] && options->min_width != -1)
		pn += ft_putfillers(' ', options->min_width - len);
	return (pn);
}
