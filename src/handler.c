/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugreyiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 13:52:34 by ugreyiro          #+#    #+#             */
/*   Updated: 2020/11/17 13:52:35 by ugreyiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

char	*handle_format(t_format format, va_list *params)
{
	char	*result;

	result = NULL;
	if (format.type == 'c')
		result = handle_char(format, params);
	else if (format.type == 's')
		result = handle_string(format, params);
	else if (format.type == 'x')
		result = handle_hex(format, params);
	else if (format.type == 'X')
		result = handle_upper_hex(format, params);
	else if (format.type == 'p')
		result = handle_pointer(format, params);
	else if (format.type == '%')
		result = handle_percent(format);
	else if (format.type == 'i' || format.type == 'd')
		result = handle_int(format, params);
	else if (format.type == 'u')
		result = handle_uint(format, params);
	return (result);
}
