/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_scanf_storagefuncs.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raica-ba <raica-ba@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 23:44:48 by raica-ba          #+#    #+#             */
/*   Updated: 2025/03/16 18:25:27 by raica-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_scanf.h"

void	store_in_char(char *c, int *j, char *buff)
{
	char	value[1];

	parse_buffer(buff, j, value);
	*c = value[0];
}

void	store_in_string(char *str, int *j, char *buff)
{
	parse_buffer(buff, j, str);
}

void	store_in_int(int *nb, int *j, char *buff)
{
	char	value[20];

	parse_buffer(buff, j, value);
	*nb = ft_atoi(value);
}

void	store_in_float(double *dec_nb, int *j, char *buff)
{
	char	value[50];

	parse_buffer(buff, j, value);
	*dec_nb = ft_atof(value);
}

void	store_in_uint(unsigned int *uint, int *j, char *buff)
{
	char	value[20];

	parse_buffer(buff, j, value);
	*uint = (unsigned int) ft_atoi(value);
}
