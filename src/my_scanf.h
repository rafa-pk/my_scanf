/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_scanf.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raica-ba <raica-ba@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 14:52:38 by raica-ba          #+#    #+#             */
/*   Updated: 2025/03/16 21:59:55 by raica-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_SCANF_H
# define MY_SCANF_H

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
void	store_in_char(char *c, int *j, char *buff);
void	store_in_string(char *str, int *j, char *buff);
void	store_in_int(int *nb, int *j, char *buff);
void	store_in_float(double *dec_nb, int *j, char *buff);
void	store_in_uint(unsigned int *uint, int *j, char *buff);
int		read_input(char *buff, int size);
int		ft_isprint(int c);
int		ft_isdigit(int c);
int		ft_atoi(char *str);
void	parse_buffer(char *buff, int *j, char *parsed_buff);
double	handle_decimals(char *str, int *i);
double	handle_exponent(double nb, char *str, int *i);
double	ft_atof(char *str);
#endif
