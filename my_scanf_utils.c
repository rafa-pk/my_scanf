/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_scanf_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raica-ba <raica-ba@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 21:00:45 by raica-ba          #+#    #+#             */
/*   Updated: 2025/03/15 15:44:51 by raica-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_scanf.h"

int	read_input(int *buff, int size)
{
	int	bytes_read;

	bytes_read = read(0, buff, size - 1);
	if (bytes_read > 0)
		buff[bytes_read] = '\0';
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

void	parse_buffer(char *buff, int *j, char *parsed_buff)
{
	int	ix;

	ix = 0;
	while (ft_isprint(buff[*j]))
		(*j)++;
	while (buff[*j] != '\0' && !ft_isprint(buff[*j]))
	{
		parsed_buff[ix] = buff[*j];
		ix++;
		(*j)++;
	}
	parsed_buff[ix] == '\0';
}
