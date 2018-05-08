/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_options.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdubinki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 10:54:36 by vdubinki          #+#    #+#             */
/*   Updated: 2017/12/19 10:54:38 by vdubinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_options.h"

static int			get_min_width(const char *format, char specifier)
{
	int		min_width;
	int		idx;

	min_width = 0;
	idx = 0;
	while (format[idx] != specifier)
	{
		if (format[idx] == '.' && ft_isdigit(format[idx + 1]))
		{
			while (ft_isdigit(format[++idx]))
				;
			continue ;
		}
		if (ft_isdigit(format[idx]) && format[idx] != '0')
		{
			min_width = ft_natoi(&format[idx]);
			while (ft_isdigit(format[++idx]))
				;
			continue ;
		}
		idx++;
	}
	return (min_width);
}

static int			get_precision(const char *format, char specifier)
{
	int		precision;
	int		idx;

	precision = -1;
	idx = 0;
	while (format[idx] != specifier)
	{
		if (format[idx] == '.')
		{
			precision = ft_natoi(&format[++idx]);
			while (ft_isdigit(format[++idx]))
				;
			continue ;
		}
		if (ft_isdigit(format[idx]))
		{
			while (ft_isdigit(format[++idx]))
				;
			continue ;
		}
		idx++;
	}
	return (precision);
}

void				get_options(const char *format,
								char specifier,
								t_options *options)
{
	int		idx;
	int		chr;

	options->min_width = get_min_width(format, specifier);
	options->precision = get_precision(format, specifier);
	idx = -1;
	while (g_flags[++idx])
		options->flags[idx] = 0;
	chr = -1;
	while (format[++chr] != specifier)
	{
		if (format[chr] == '0' && chr != 0)
			if (ft_isdigit(format[chr - 1]) ||
				format[chr - 1] == '.')
				continue ;
		idx = -1;
		while (g_flags[++idx])
			if (g_flags[idx] == format[chr] && !options->flags[idx])
			{
				options->flags[idx] = 1;
				break ;
			}
	}
}
