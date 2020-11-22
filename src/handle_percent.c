/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_percent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugreyiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 14:40:27 by ugreyiro          #+#    #+#             */
/*   Updated: 2020/11/19 14:40:28 by ugreyiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

char	*handle_percent(t_format format)
{
	char	*result;

	result = malloc(sizeof(char) * 2);
	if (result)
	{
		result[0] = '%';
		result[1] = '\0';
	}
	else
		return (NULL);
	if ((format.flags & FLG_ZER) && !(format.flags & FLG_MIN))
		result = add_smb(result, format.width - (int)ft_strlen(result), '0', 0);
	else if (format.flags & FLG_MIN)
		result = add_smb(result, format.width - (int)ft_strlen(result), ' ', 1);
	else
		result = add_smb(result, format.width - (int)ft_strlen(result), ' ', 0);
	return (result);
}
