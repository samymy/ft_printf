/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_converter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdubinki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 11:52:57 by vdubinki          #+#    #+#             */
/*   Updated: 2017/12/14 11:52:59 by vdubinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "str_func.h"
#include "ft_wctomb.h"
#include "other_converters.h"

/*
**int		cuc_converter(va_list ap, int length_modifier, t_options *options)
**{
**	char	arg;
**	int		pn;
**
**	(void)length_modifier;
**	arg = va_arg(ap, int);
**	pn = 0;
**	if (!options->flags[0])
**	{
**		if (options->flags[2])
**			pn += ft_putfillers('0', options->min_width - 1);
**		else
**			pn += ft_putfillers(' ', options->min_width - 1);
**	}
**	pn += ft_nputstr(ft_wctomb(arg));
**	if (options->flags[0])
**		pn += ft_putfillers(' ', options->min_width - 1);
**	return (pn);
**}
*/

int		cuc_converter(va_list ap, int length_modifier, t_options *options)
{
	return (char_converter((char)va_arg(ap, int), length_modifier, options));
}

int		c_converter(va_list ap, int length_modifier, t_options *options)
{
	if (length_modifier == 3)
		return (cuc_converter(ap, -1, options));
	return (char_converter((char)va_arg(ap, int), length_modifier, options));
}
