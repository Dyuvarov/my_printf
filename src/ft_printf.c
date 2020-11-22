/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugreyiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 13:14:02 by ugreyiro          #+#    #+#             */
/*   Updated: 2020/11/16 13:14:04 by ugreyiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static int	error_exit(va_list *params)
{
	va_end(*params);
	return (-1);
}

static int	print_char(t_format format, char *str_format)
{
	int width;

	width = (format.width < 1) ? 1 : format.width;
	return (write(1, str_format, width));
}

static int	work_on_percent(const char *str, va_list *params, int *i, int *res)
{
	char		*str_format;
	t_format	format;
	int			wr_res;

	wr_res = 0;
	format = parse(&(str[*i]), params);
	if (!(str_format = handle_format(format, params)))
		return (-1);
	if (format.type == 'c')
	{
		if ((wr_res = print_char(format, str_format)) < 0)
			return (-1);
		*res += wr_res;
	}
	else
	{
		ft_putstr_fd(str_format, 1);
		*res += ft_strlen(str_format);
	}
	free(str_format);
	*i += format.length;
	return (1);
}

int			ft_printf(const char *str, ...)
{
	va_list	params;
	int		i;
	int		result;

	va_start(params, str);
	i = 0;
	result = 0;
	while (str[i])
	{
		while (str[i] != '%' && str[i])
		{
			write(1, &(str[i]), 1);
			++i;
			++result;
		}
		if (str[i])
		{
			if ((work_on_percent(str, &params, &i, &result)) < 0)
				return (error_exit(&params));
		}
	}
	va_end(params);
	return (result);
}
