/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   S_converter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdubinki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 10:17:40 by vdubinki          #+#    #+#             */
/*   Updated: 2017/12/14 10:17:42 by vdubinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "str_func.h"
#include "ft_wctomb.h"

static int			print_prefix(int len, t_options *options)
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

static char			*get_mb(wchar_t *wc_arg)
{
	char	*arg;
	char	*tmp;

	if (!wc_arg)
		return (ft_strdup("(null)"));
	arg = ft_strdup("");
	while (*wc_arg != L'\0')
	{
		tmp = arg;
		arg = ft_strjoin(arg, ft_wctomb(*wc_arg++));
		free(tmp);
	}
	return (arg);
}

static char			*get_mb_by_precision(wchar_t *wc_arg, int precision,
															int *len)
{
	char	*arg;
	char	*tmp;
	char	*wchar;

	if (!wc_arg)
		return (ft_strdup("(null)"));
	arg = ft_strdup("");
	*len = 0;
	while (*wc_arg != L'\0')
	{
		wchar = ft_wctomb(*wc_arg++);
		if (*len + ft_strlen(wchar) <= (unsigned long)precision)
		{
			tmp = arg;
			arg = ft_strjoin(arg, wchar);
			*len += ft_strlen(wchar);
			free(tmp);
		}
	}
	return (arg);
}

int					suc_converter(va_list ap,
									int length_modifier,
									t_options *options)
{
	wchar_t	*wc_arg;
	char	*arg;
	int		len;
	int		pn;

	(void)length_modifier;
	wc_arg = va_arg(ap, wchar_t *);
	arg = get_mb(wc_arg);
	len = ft_strlen(arg);
	pn = 0;
	if (options->precision != -1)
		if (options->precision < len)
		{
			free(arg);
			arg = get_mb_by_precision(wc_arg,
									options->precision, &len);
		}
	pn += print_prefix(len, options);
	pn += ft_nputstr(arg);
	if (options->flags[0] && options->min_width != -1)
		pn += ft_putfillers(' ', options->min_width - len);
	free(arg);
	return (pn);
}
