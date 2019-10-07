/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneuda <nneuda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 10:14:44 by nneuda            #+#    #+#             */
/*   Updated: 2019/10/06 23:13:44 by nneuda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*dub_itoa(char *str, int i, int n)
{
	if (n >= 0 && str)
	{
		str[i++] = '0' + (n % 10);
		n /= 10;
		while (n != 0)
		{
			str[i++] = '0' + (n % 10);
			n /= 10;
		}
	}
	else if (str)
	{
		str[i++] = '0' - (n % 10);
		n /= 10;
		while (n != 0)
		{
			str[i++] = '0' - (n % 10);
			n /= 10;
		}
		str[i++] = '-';
	}
	return (str);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		size;
	int		i;

	i = 0;
	size = ft_numlen(n);
	if (!(str = ft_strnew(size)))
		return (NULL);
	str = dub_itoa(str, i, n);
	i = (int)ft_strlen(str);
	str[i] = '\0';
	ft_strrev(str);
	return (ft_strdup(str));
}
