/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_scanf.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raica-ba <raica-ba@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 14:52:38 by raica-ba          #+#    #+#             */
/*   Updated: 2025/03/15 15:49:25 by raica-ba         ###   ########.fr       */
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
int		fmt_specs(char fmt_spec, va_list ap, int *j, char *buff);
void	store_in_char(char *c);
void	store_in_string(char *str);
void	store_in_int(int *nb);
void	store_in_float(float *dec_nb);
void	store_in_uint(unsigned int *uint);
int		read_input(int *buff, int size);
size_t	ft_strlen(char *str);
int		ft_isprint(int c);
int		ft_atoi(char *str);
void	parse_buffer(char *buff, int *j, char *parsed_buff);

#endif
