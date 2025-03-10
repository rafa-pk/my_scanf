/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_scanf.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raica-ba <raica-ba@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 14:52:38 by raica-ba          #+#    #+#             */
/*   Updated: 2025/03/10 23:54:23 by raica-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_SCANF_H
# define MYSCANF_H

# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <string.h>
# include <stdint.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 50
# endif

int		my_scanf(const char *str, ...);
char	*store_in_char(char *c);
char	*store_in_string(char *str);
int		*store_in_int(int *nb);
float   *store_in_float(float *dec_nb);
unsigned int    *store_in_uint(unsigned int *uint);

#endif
