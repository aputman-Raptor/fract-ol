/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrealloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 14:56:27 by aputman           #+#    #+#             */
/*   Updated: 2016/06/07 15:08:33 by aputman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrealloc(char *str, int size)
{
	char	*tmp;

	if (!(tmp = ft_strnew(ft_strlen(str) + 1)))
		return (NULL);
	ft_strcpy(tmp, str);
	free(str);
	if (!(str = ft_strnew(ft_strlen(tmp) + 1 + size)))
		return (NULL);
	ft_strcpy(str, tmp);
	free(tmp);
	return (str);
}
