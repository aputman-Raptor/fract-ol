/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 14:16:07 by aputman           #+#    #+#             */
/*   Updated: 2016/04/09 16:24:50 by aputman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					malloc_dat_shit(char **str)
{
	char			*tmp;

	if (!(tmp = (char *)ft_strnew(ft_strlen(*str) + 1)))
		return (0);
	ft_strcpy(tmp, *str);
	free(*str);
	if (!(*str = ft_strnew(ft_strlen(tmp) + BUFF_SIZE + 1)))
		return (0);
	ft_strcpy(*str, tmp);
	free(tmp);
	return (1);
}

char				*do_ur_shit(char *str, char **line, int rd)
{
	int				i;
	char			*tmp;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	free(*line);
	*line = ft_strsub(str, 0, i);
	if ((rd == 0 && ft_strchr(str, '\n')) || rd != 0)
	{
		tmp = ft_strsub(str, (i + 1), ft_strlen(str));
		free(str);
		str = ft_strsub(tmp, 0, ft_strlen(tmp));
	}
	else
	{
		free(str);
		str = ft_strdup("\0");
	}
	return (str);
}

int					get_next_line(const int fd, char **line)
{
	static	char	*str;
	int				rd;

	if (line == NULL || fd < 0 || !(*line = ft_strnew(BUFF_SIZE)))
		return (-1);
	if (!str && !(str = ft_strnew(BUFF_SIZE + 1)))
		return (-1);
	while ((rd = read(fd, *line, BUFF_SIZE)) > 0)
	{
		if (!(malloc_dat_shit(&str)))
			return (-1);
		ft_strncat(str, *line, BUFF_SIZE);
		if (ft_strchr(str, '\n'))
			break ;
		free(*line);
		if (!(*line = ft_strnew(BUFF_SIZE)))
			return (-1);
	}
	if (rd == 0 && str[0] == '\0')
		return (0);
	if (rd == -1 || !(str = do_ur_shit(str, &(*line), rd)))
		return (-1);
	return (1);
}
