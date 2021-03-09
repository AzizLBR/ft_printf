/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubar <aloubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 16:06:54 by aloubar           #+#    #+#             */
/*   Updated: 2021/03/09 10:58:51 by aloubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

# include <stdlib.h>
# include "libft.h"
# include <stdarg.h>
# include <stdio.h>

typedef	struct	 s_info
{
	va_list		args;
	int			width;
	int			return_value;
	int			i;
	char		spe;
	int			zero;
	int			minus;
	int			star;
	int			dot;
	int			dot_exist;
	int			bdot;
	char		buff[1024];
	int			j;
	int			len_variable;
	int			len_width;
	int			len_dot;
	int			point_null;
	int			minus_done;
	int			flag_0;
	int			nb_neg;
}				t_info;

t_info			*ft_parse_minus(t_info *info);
t_info			*ft_parse_star(t_info *info);
t_info			*ft_parse_dot(t_info *info, const char *str);
t_info			*ft_parse_nb(t_info *info, char c);
int				ft_check_type(char c);
int				ft_check_flags(char c);
void			ft_buff_no_flags(t_info *info, char c);
void			ft_add_to_buff(t_info *info, char *str, int len);
void			ft_display_buff(t_info *info);
void			ft_treat_char(t_info *info, int c);
char			*ft_treat_width(t_info *info);
int				ft_printf(const char *format, ...);
void			ft_treat_string(t_info *info, char *str);
void			ft_treat_int(t_info *info, int nb);
void			ft_itoa_remixed(long long int n, char *str, t_info *info);
void			ft_treat_point(t_info *info, unsigned long long int nb);
char			*ft_strcpy(char *s1, char *s2);
void			ft_add_prec_display(t_info *info, char *str, char *str_of_dot,
				int nb);
void			ft_precision(t_info *info,  char *str_of_dot);
void			ft_treat_unsigned(t_info *info, unsigned int nb);
void			ft_treat_hexa(t_info *info, unsigned int nb);

#endif
