/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_scanf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raica-ba <raica-ba@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:02:01 by raica-ba          #+#    #+#             */
/*   Updated: 2025/03/15 15:02:26 by raica-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_scanf.h"

int	my_scanf(const char *fmt, ...)
{
	va_list	ap;
	int		i;
	int		j;
	char	buff[BUFFER_SIZE];
	int		matched;

	if (!fmt)
		return (0);
	va_start(ap, fmt);
	i = 0;
	j = 0;
	matched = 0;
	if (read_input(buff, BUFFER_SIZE) <= 0 || BUFFER_SIZE < 0)
	{
		va_end(ap);
		return (0);
	}
	while (fmt[i] != '\0')
	{
		if (fmt[i] == '%' && fmt[i + 1])
		{
			matched += fmt_specs(fmt[i + 1], ap, &j, buff);
			i++;
		}
		else
		{
			if (buff[j] == fmt[i])
				j++;
			else
				break ;
		}
		i++;
	}
	va_end(ap);
	return (matched);
}

int	fmt_specs(char fmt_spec, va_list ap, int *j, char *buff)
{
	int	match;

	match = 0;
	if (fmt_spec == 'c')
	{
		store_in_char(va_arg(ap, char *), j, buff);
		match++;
	}
	else if (fmt_spec == 's')
	{
		store_in_string(va_arg(ap, char *), j, buff);
		match++;
	}
	else if (fmt_spec == 'd' || fmt_spec == 'i')
	{
		store_in_int(va_arg(ap, int *), j, buff);
		match++;
	}
	else if (fmt_spec == 'f')
	{
		store_in_float(va_arg(ap, double *), j, buff);
		match++;
	}
	else if (fmt_spec == 'u')
	{
		store_in_uint(va_arg(ap, unsigned int *), j, buff);
		match++;
	}
	return (match);
}
