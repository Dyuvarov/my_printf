/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugreyiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 11:05:27 by ugreyiro          #+#    #+#             */
/*   Updated: 2020/11/18 11:05:29 by ugreyiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include "libft.h"

char	*space_str(int n)
{
	char	*result;

	if (n < 0)
		n = 0;
	if (!(result = (char *)malloc(sizeof(char) * (n + 1))))
		return (NULL);
	result[n] = '\0';
	while (--n >= 0)
		result[n] = ' ';
	return (result);
}

char	*zero_str(int n)
{
	char	*result;

	if (n < 0)
		n = 0;
	if (!(result = (char *)malloc(sizeof(char) * (n + 1))))
		return (NULL);
	result[n] = '\0';
	while (--n >= 0)
		result[n] = '0';
	return (result);
}

int		dec_nbrlen(int nbr)
{
	int	i;

	if (nbr == 0)
		return (1);
	i = 0;
	while (nbr > 0)
	{
		nbr /= 10;
		++i;
	}
	return (i);
}

int		hex_nbrlen(unsigned int nbr)
{
	int	i;

	if (nbr == 0)
		return (1);
	i = 0;
	while (nbr > 0)
	{
		nbr /= 16;
		++i;
	}
	return (i);
}

char	*null_str(void)
{
	char	*str;

	if (!(str = (char*)malloc(sizeof(char) * 7)))
		return (NULL);
	str[0] = '(';
	str[1] = 'n';
	str[2] = 'u';
	str[3] = 'l';
	str[4] = 'l';
	str[5] = ')';
	str[6] = '\0';
	return (str);
}
