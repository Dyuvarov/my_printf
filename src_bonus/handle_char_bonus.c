/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugreyiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 13:51:36 by ugreyiro          #+#    #+#             */
/*   Updated: 2020/11/17 13:51:41 by ugreyiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include "libft.h"

static void	add_spaces(char **str, int len, int last_ind)
{
	char *tmp;

	tmp = *str;
	while (len >= last_ind)
	{
		tmp[len] = ' ';
		--len;
	}
}

char		*handle_char(t_format format, va_list *params)
{
	char	*result;
	int		len;

	len = (format.width > 1) ? format.width : 1;
	if (!(result = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	result[len] = '\0';
	if (len > 1)
	{
		len--;
		if (format.flags & FLG_MIN)
		{
			add_spaces(&result, len, 1);
			result[0] = va_arg(*params, int);
		}
		else
		{
			result[len] = va_arg(*params, int);
			add_spaces(&result, len - 1, 0);
		}
	}
	else
		result[0] = va_arg(*params, int);
	return (result);
}
