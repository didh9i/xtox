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
/*   ft_atod.c                                cclarice@student.21-school.ru   */
/*                                                                            */
/*   Created/Updated: 2021/05/12 01:07:04  /  2021/05/12 11:14:00 @cclarice   */
/*                                                                            */
/* ************************************************************************** */

#include "../xtox.h"
#include <unistd.h>
#include <stdio.h>

void	ft_atod_exp(double *l, double *r, int e)
{
	while (e >= 1)
	{
		*l *= 10;
		*r *= 10;
		--e;
	}
	while (e <= -1)
	{
		*l /= 10;
		*r /= 10;
		++e;
	}
}

void	ft_atod_reg(const char *str, double *l, double *r)
{
	if (*str == '.' && ++str)
	{
		while (str[1] >= '0' && str[1] <= '9')
			++str;
		while (*str >= '0' && *str <= '9')
		{
			*r += *str-- - '0';
			*r /= 10;
		}
		++str;
		while (*str >= '0' && *str <= '9')
			str++;
	}
	if (*str == 'e')
		ft_atod_exp(l, r, ft_atoi(++str));
	*l += *r;
}

double	ft_atod(const char *str)
{
	const char		sgn = 1 - (*str == '-') * 2;
	double		r;
	double		l;

	r = 0;
	l = 0;
	str += (*str == '-' || *str == '+');
	while (*str == '0')
		++str;
	while (*str >= '0' && *str <= '9')
	{
		l *= 10;
		l += *str++ - '0';
	}
	ft_atod_reg(str, &l, &r);
	return (sgn * (l));
}

/*
double	ft_atod(const char *str)
{
	const char	sgn = ternar_sgn(*str, '-', 1, -1);
	double		r;
	double		l;

	r = 0;
	l = 0;
	if (*str == '-' || *str == '+')
		++str;
	while (*str >= '0' && *str <= '9')
	{
		l *= 10;
		l += *str++ - '0';
	}
	if (*str == '.' && ++str)
	{
		while (str[1] >= '0' && str[1] <= '9')
			++str;
		while (*str >= '0' && *str <= '9')
		{
			r += *str-- - '0';
			r *= 0.1;
		}	
	}
	return (sgn * (l + r));
}
*/