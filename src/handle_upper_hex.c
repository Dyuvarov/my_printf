/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_upper_hex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugreyiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 13:32:32 by ugreyiro          #+#    #+#             */
/*   Updated: 2020/11/19 13:32:33 by ugreyiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

char		*handle_upper_hex(t_format format, va_list *params)
{
	char	*result;
	int		i;

	i = 0;
	result = handle_hex(format, params);
	if (!result)
		return (NULL);
	while (result[i])
	{
		result[i] = ft_toupper(result[i]);
		++i;
	}
	return (result);
}
