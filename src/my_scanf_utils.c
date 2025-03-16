/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_scanf_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raica-ba <raica-ba@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 21:00:45 by raica-ba          #+#    #+#             */
/*   Updated: 2025/03/16 18:40:10 by raica-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_scanf.h"

int	read_input(char *buff, int size)
{
	int	bytes_read;

	bytes_read = read(0, buff, size - 1);
	if (bytes_read > 0)
		buff[bytes_read] = '\0';
	else if (bytes_read == 0)
		buff[0] = '\0';
	return (bytes_read);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

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

int	ft_atoi(char *str)
{
	int	i;
	int	nb;
	int	sinal;

	i = 0;
	nb = 0;
	sinal = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sinal = -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		nb *= 10;
		nb += str[i] - 48;
		i++;
	}
	return (nb * sinal);
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
	int		j;
	int		exp_sign;
	double	val;
	double	res;

	j = 0;
	exp_sign = 1;
	val = 1.0;
	res = 0.0;
	if (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
			exp_sign = -1;
		(*i)++;
	}
	while (ft_isdigit(str[*i]))
	{
		res = res * 10 + (str[*i] - 48);
		(*i)++;
	}
	while (j < res)
	{
		val *= 10.0;
		j++;
	}
	if (exp_sign == -1)
		return (nb / val);
	else
		return (nb * val);
}

double	ft_atof(char *str)
{
	int		i;
	int		sign;
	double	nb;

	i = 0;
	sign = 1;
	nb = 0.0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		nb *= 10;
		nb += str[i] - 48;
		i++;
	}
	if (str[i] == '.')
	{
		i++;
		nb += handle_decimals(str, &i);
	}
	if (str[i] == 'e' || str[i] == 'E')
	{
		i++;
		nb = handle_exponent(nb, str, &i);
	}
	return (sign * nb);
}

void	parse_buffer(char *buff, int *j, char *parsed_buff)
{
	int	ix;

	ix = 0;
	while (!ft_isprint(buff[*j]))
		(*j)++;
	while (buff[*j] != '\0' && ft_isprint(buff[*j]))
	{
		parsed_buff[ix] = buff[*j];
		ix++;
		(*j)++;
	}
	parsed_buff[ix] = '\0';
}
