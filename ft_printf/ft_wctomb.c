/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wctomb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdubinki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 10:05:54 by vdubinki          #+#    #+#             */
/*   Updated: 2017/12/14 10:05:56 by vdubinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_wctomb.h"

static int		get_active_bits_count(int nbr)
{
	int		ab;

	ab = 0;
	while (nbr != 0)
	{
		ab++;
		nbr /= 2;
	}
	return (ab);
}

static char		*get_mb_by_wc(char *mb, int wc_code, int ab)
{
	if (ab <= 7)
		mb[0] = 0 | wc_code;
	else	if (ab <= 11)
	{
		mb[0] = 192 | (wc_code >> 6);
		mb[1] = 128 | (wc_code & 63);
	}
	else	if (ab <= 16)
	{
		mb[0] = 224 | (wc_code >> 12);
		mb[1] = 128 | ((wc_code >> 6) & 63);
		mb[2] = 128 | (wc_code & 63);
	}
	else
	{
		mb[0] = 240 | (wc_code >> 18);
		mb[1] = 128 | ((wc_code >> 12) & 63);
		mb[2] = 128 | ((wc_code >> 6) & 63);
		mb[3] = 128 | (wc_code & 63);
	}
	return (mb);
}

char			*ft_wctomb(wchar_t wc)
{
	static char		mb[5];
	int				wc_code;

	ft_bzero(&mb[0], 5);
	wc_code = (int)wc;
	return (get_mb_by_wc(&mb[0], wc_code, get_active_bits_count(wc_code)));
}
