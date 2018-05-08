/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_converters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdubinki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 10:39:24 by vdubinki          #+#    #+#             */
/*   Updated: 2017/12/19 10:39:26 by vdubinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "other_converters.h"

int			char_converter(char arg, int length_modifier, t_options *options)
{
	int		pn;

	(void)length_modifier;
	pn = 0;
	if (!options->flags[0])
	{
		if (options->flags[2])
			pn += ft_putfillers('0', options->min_width - 1);
		else
			pn += ft_putfillers(' ', options->min_width - 1);
	}
	pn += write(1, &arg, 1);
	if (options->flags[0])
		pn += ft_putfillers(' ', options->min_width - 1);
	return (pn);
}

int			duc_converter(va_list ap,
									int length_modifier,
									t_options *options)
{
	length_modifier = 3;
	return (d_converter(ap, length_modifier, options));
}

int			uuc_converter(va_list ap,
									int length_modifier,
									t_options *options)
{
	length_modifier = 3;
	return (u_converter(ap, length_modifier, options));
}
