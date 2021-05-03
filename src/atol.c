/* ************************************************************************** */
/*                                                                            */
/*       ::::::    ::::::   :::  ::::::::  ::::::::   :::  ::::::    :::::::  */
/*     :+:   :+: :+:   :+: :+: :+:   :+:  :+:    :+: :+: :+:   :+: :+:    :+: */
/*    +:+       +:+       +:+ +:+   +:+  +:+    +:+     +:+       +:+    +:+  */
/*   +#+       +:+       +#+ +:+   +#+  +:+    +#+ +:+ +#+       +#+:+:+#+:   */
/*  +#+       +#+       +#+   +#+#+#+# #+#+#+#+   +#+ +#+       +#+           */
/* #+#   #+# #+#   #+# #+#            #+#    #+# #+# #+#   #+# #+#    #+#     */
/*  ######    ######  ############## ###    ### ###   ######    #######       */
/*                                                                            */
/* ************************************************************************** */
/*                                                                            */
/*   atol.c                                   cclarice@student.21-school.ru   */
/*                                                                            */
/*   Created/Updated: 2021/05/01 19:00:25  /  2021/05/02 16:40:23 @cclarice   */
/*                                                                            */
/* ************************************************************************** */

#include "../xtox.h"

int	ternar(char a, char b, int c, int d)
{
	if (a == b)
		return (d);
	else
		return (c);
}

long	ft_atol(char *str)
{
	const char	sgn = ternar(*str, '-', 1, -1);
	long		ret;

	ret = 0;
	if (*str == '+' || *str == '-')
		str++;
	while (*str == '0')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		ret *= 10;
		ret += *str - '0';
		if (ret & 0x8000000000000000)
		{
			if (sgn == 1)
				return (0x7fffffffffffffff);
			else
				return (0x8000000000000000);
		}
		str++;
	}
	return (ret * sgn);
}