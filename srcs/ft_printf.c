/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubar <aloubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 16:10:26 by aloubar           #+#    #+#             */
/*   Updated: 2021/02/17 10:19:23 by aloubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/ft_printf.h"

void		ft_putflagtozero(t_info *info)
{
	info->zero = 0;
	info->minus = 0;
	info->star = 0;
	info->dot = 0;
	info->dot_exist = 1;
	info->bdot = 0;
	info->width = 0;
	info->spe = '\0';
}
/*
void		ft_putstr(char *str)
{
	int i; 

	i = -1;
	while (str[i++])
		write(1, &str[i], 1);
}

void		ft_display_char(t_info *info)
{
	char c;

	c = (char)va_arg(info->args, int);
	write(1, &c, 1);
	info->return_value++;
}

void		ft_display_str(t_info *info)
{
	char *str;

	str = (char *)va_arg(info->args, char *);
	ft_putstr(str);
}

void		ft_display_int(t_info *info)
{
	int nb;

	nb = (int)va_arg(info->args, int);
	if (nb < 0 && info->spe == 'i')
		return ;
	ft_putnbr_fd(nb, 1);
}
*/
void		ft_parse_flags(t_info *info, const char *str)
{
	while (str[info->i])
	{
		if ((!(ft_check_type(str[info->i]))) && 
				(!(ft_check_flags(str[info->i]))) && 
				(!(ft_isdigit(str[info->i]))))
			break;
		if (str[info->i] == '0' && info->minus == 0 && info->width == 0)
			info->zero = 1;
		if (str[info->i] == '-')
		{
			info->zero = 0;
			info->minus = 1;
		}
		if (str[info->i] == '*')
			ft_parse_star(info);
		if (str[info->i] == '.')
			ft_parse_dot(info, str);
		if (ft_isdigit(str[info->i]))
			ft_parse_nb(info, str[info->i]);
		if (ft_check_type(str[info->i]))
		{
			info->spe = str[info->i];
			break ;
		}
		info->i++;
	}
}

void		ft_exec_flags(t_info *info)
{
	if (info->spe == 'c')
		ft_treat_char(info, va_arg(info->args, int));
/*
	else if (spe->info == 'd' || str[info->i] == 'i')
		ft_display_int(info);
//	else if (info->spe  == 'x' || info->spe == 'X' || info->spe == u)

	else if (str[info->i] == 's')
		ft_display_str(info);
//	else if (str[info->i] == 'p')
*/
}

int		ft_printf(const char *format, ...)
{
	t_info	info;
	char	*str;

	str = ft_strdup(format);
	info.i = 0;
	info.return_value = 0;
	va_start(info.args, format);
	while (str && str[info.i])
	{
		ft_putflagtozero(&info);
		if (!str)
			break ;
		if (str[info.i - 1] == '%' && info.i != 0)
		{
			ft_parse_flags(&info, str);
			if (ft_check_type(str[info.i]))
				ft_exec_flags(&info);
			else
				ft_buff_no_flags(&info, str[info.i]);
		}
		else if (str[info.i - 1] != '%' && str[info.i] != '%')
			ft_buff_no_flags(&info, str[info.i]);
		info.i++;
	}
	va_end(info.args);
	ft_display_buff(&info);
	free(str);
	return (info.return_value);
}
/*
int main(void)
{
	char c;

	c = 'p';
	ft_printf("%c", c);
	ft_printf("\n");
	ft_printf("%c\n", c);
}*/
