/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_scanf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raica-ba <raica-ba@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:02:01 by raica-ba          #+#    #+#             */
/*   Updated: 2025/03/10 23:05:28 by raica-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_scanf.h"

int	my_scanf(const char *fmt, ...)
{
	va_list	ap;
	int		i;
	int		input_read;
	char	buff[BUFFER_SIZE];
	int		matched;

	if (!fmt)
		return (0);
	va_start(ap, fmt);
	i = 0;
	matched = 0;
	input_read = read(0, buff, BUFFER_SIZE - 1);
	if (input_read <= 0)
	{
		va_end(ap);
		return (0);
	}
	buff[input_read] = '\0';
	while (fmt[i] != '\0')
	{
		if (fmt[i] == '%' && fmt[i + 1])
		{
			matched += fmt_specs(fmt[i + 1], ap);
			i++;
		}
		else
		{
			if (buff[i] == fmt[i])
				i++;
			else
				break ;
		}
		i++;
	}
	va_end(ap);
	return (matched);
}

int	fmt_specs(char	fmt_spec, va_list ap)
{
	int	match;

	match = 0;
	if (fmt_spec == 'c')
	{
		
		match++;
	}
	else if (fmt_spec == 's')
	
	else if (fmt_spec == 'd' || fmt_spec == 'i')
	
	else if (fmt_spec == 'f')

	else if (fmt_spec == 'u')
}
