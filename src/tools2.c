/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugreyiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 12:27:50 by ugreyiro          #+#    #+#             */
/*   Updated: 2020/11/21 12:27:56 by ugreyiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"

char	*add_smb(char *str, int num, char smb, int pos)
{
	char	*str_to_add;
	char	*result;

	if (!str)
		return (NULL);
	if (smb == ' ')
		str_to_add = space_str(num);
	else
		str_to_add = zero_str(num);
	if (!str_to_add)
	{
		free(str);
		return (NULL);
	}
	if (pos == 0)
		result = ft_strjoin(str_to_add, str);
	else
		result = ft_strjoin(str, str_to_add);
	free(str);
	free(str_to_add);
	return (result);
}
