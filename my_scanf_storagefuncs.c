/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_scanf_storagefuncs.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raica-ba <raica-ba@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 23:44:48 by raica-ba          #+#    #+#             */
/*   Updated: 2025/03/11 16:50:30 by raica-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_scanf.h"

char	*store_in_char(char *c, int i, char *buff)
{
	if (buff[i] != '\0') 
		*c = buff[i];
}

char	*store_in_string(char *str, int i, char *buff)
{
	int	j;

	j = 0;
	while (buff[i] == ' ' || buff['\n'])
		i++;
	while (buff)
}

int	*store_in_int(int *nb)
{

}

float	*store_in_float(float *dec_nb)
{

}

unsigned int	*store_in_uint(unsigned int *uint)
{

}
