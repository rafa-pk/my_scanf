/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_scanf_auxiliaryfuncs.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raica-ba <raica-ba@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 22:07:26 by raica-ba          #+#    #+#             */
/*   Updated: 2025/03/16 22:22:44 by raica-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_scanf.h"

int	ft_isprint(int c)
{
	if ((c >= 32 && c <= 126))
		return (1);
	else
		return (0);
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

double	handle_decimals(char *str, int *i)
{
	double	fraction;
	double	divisor;

	fraction = 0.0;
	divisor = 10.0;
	while (ft_isdigit(str[*i]))
	{
		fraction += (str[*i] - 48) / divisor;
		divisor *= 10.0;
		(*i)++;
	}
	return (fraction);
}

double	handle_exponent(double nb, char *str, int *i)
{
	int		exp_sign;
	double	mult;
	double	exp;

	exp_sign = 1;
	mult = 1.0;
	exp = 0.0;
	if (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
			exp_sign = -1;
		(*i)++;
	}
	while (ft_isdigit(str[*i]))
	{
		exp = exp * 10 + (str[*i] - 48);
		(*i)++;
	}
	while (exp > 0)
	{
		if (exp_sign == 0)
			mult *= 10.0;
		else
			mult /= 10.0;
		exp--;
	}
	return (nb * mult);
}
