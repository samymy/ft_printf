/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdubinki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 08:50:59 by vdubinki          #+#    #+#             */
/*   Updated: 2017/11/24 08:51:02 by vdubinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "str_func.h"
#include "other_converters.h"
#include "get_specifier.h"
#include "get_options.h"

static void			get_length_modifier(const char *format,
										char specifier,
										int *length_modifier)
{
	int		idx;
	int		len;

	*length_modifier = -1;
	idx = -1;
	len = ft_strchr(format, specifier) - format;
	while (g_length_modifiers[++idx])
		if (ft_strnstr(format,
						g_length_modifiers[g_length_modifiers_priorities[idx]],
						len))
		{
			*length_modifier = g_length_modifiers_priorities[idx];
			break ;
		}
}

static int			to_null(const char **format)
{
	while (**format != '\0')
		(*format)++;
	return (0);
}

static int			convert(va_list ap, const char **format)
{
	const char	*specifier;
	int			idx;
	int			length_modifier;
	t_options	options;

	if (!(specifier = get_specifier(*format)))
		return (to_null(format));
	get_options(*format, *specifier, &options);
	get_length_modifier(*format, *specifier, &length_modifier);
	idx = -1;
	while (g_specifiers[++idx].symbol)
		if (g_specifiers[idx].symbol == *specifier)
		{
			if (!g_specifiers[idx].length_modifiers[length_modifier])
				length_modifier = -1;
			*format = ++specifier;
			return (g_specifiers[idx].converter(ap,
													length_modifier,
													&options));
		}
	*format = specifier;
	(*format)++;
	return (char_converter(*specifier, length_modifier, &options));
}

int					ft_printf(const char *format, ...)
{
	va_list		ap;
	int			pn;

	va_start(ap, format);
	pn = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			pn += convert(ap, &format);
			continue ;
		}
		pn += write(1, format++, 1);
	}
	va_end(ap);
	return (pn);
}
