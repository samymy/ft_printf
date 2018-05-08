/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wctomb.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdubinki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 10:05:48 by vdubinki          #+#    #+#             */
/*   Updated: 2017/12/14 10:05:51 by vdubinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_WCTOMB_H
# define FT_WCTOMB_H

# include <wchar.h>
# include <stdlib.h>

# include "ft_printf.h"

char	*ft_wctomb(wchar_t wc);

#endif
