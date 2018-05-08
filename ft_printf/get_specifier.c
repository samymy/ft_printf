/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_specifier.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdubinki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 10:48:58 by vdubinki          #+#    #+#             */
/*   Updated: 2017/12/19 10:49:00 by vdubinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_specifier.h"

static int			is_flag(const char format)
{
	int		idx;

	idx = -1;
	while (g_flags[++idx])
		if (g_flags[idx] == format)
			return (1);
	return (0);
}

static int			is_length_modifier(const char *format, int *length)
{
	int		idx;
	int		len;

	idx = -1;
	while (g_length_modifiers[++idx])
	{
		len = ft_strlen(g_length_modifiers[idx]);
		if (!ft_strncmp(format, g_length_modifiers[idx], len))
		{
			*length = len;
			return (1);
		}
	}
	return (0);
}

static int			pseudo_specifier(const char *format)
{
	int		len;

	if (is_flag(*format))
		return (1);
	if (is_length_modifier(format, &len))
		return (len);
	if (ft_isdigit(*format))
		return (1);
	if (*format == '.')
		return (1);
	return (0);
}

const char			*get_specifier(const char *format)
{
	int		chr;
	int		idx;
	int		ret;

	chr = -1;
	while (format[++chr] != '\0')
	{
		idx = -1;
		while (g_specifiers[++idx].symbol)
			if (g_specifiers[idx].symbol == format[chr])
				return (&format[chr]);
		ret = pseudo_specifier(&format[chr]);
		if (!ret)
			return (&format[chr]);
		chr += ret - 1;
	}
	return (0);
}
