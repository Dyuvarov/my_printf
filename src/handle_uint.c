/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_uint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugreyiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 11:32:19 by ugreyiro          #+#    #+#             */
/*   Updated: 2020/11/21 11:32:21 by ugreyiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

char	*handle_uint(t_format format, va_list *params)
{
	char			*result;
	unsigned int	nbr;

	nbr = va_arg(*params, int);
	if (format.accuracy == 0 && nbr == 0)
		result = space_str(0);
	else
		result = ft_itoa(nbr);
	if (!result)
		return (NULL);
	if (format.accuracy > 0)
		result = add_smb(result, format.accuracy - (int)ft_strlen(result)
				, '0', 0);
	if (!result)
		return (NULL);
	if ((format.flags & FLG_ZER) && (format.accuracy < 0))
		result = add_smb(result, format.width - (int)ft_strlen(result), '0', 0);
	else if (format.flags & FLG_MIN)
		result = add_smb(result, format.width - (int)ft_strlen(result), ' ', 1);
	else
		result = add_smb(result, format.width - (int)ft_strlen(result), ' ', 0);
	return (result);
}
