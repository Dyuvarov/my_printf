/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugreyiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 13:51:50 by ugreyiro          #+#    #+#             */
/*   Updated: 2020/11/15 16:18:39 by ugreyiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

t_format	parse(const char *str, va_list *params)
{
	t_format	format;

	format.length = 1;
	parse_flags(&format, str);
	parse_width(&format, str, params);
	parse_accuracy(&format, str, params);
	parse_type(&format, str);
	return (format);
}
