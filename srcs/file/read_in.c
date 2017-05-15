/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_in.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yherrera <yherrera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 16:24:41 by yherrera          #+#    #+#             */
/*   Updated: 2017/05/15 12:35:20 by yherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdrs/read_in.h"

static char	*ft_strcat_e(char *s1, const char *s2, int len)
{
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	while (s2[i])
	{
		s1[len + i] = s2[i];
		i++;
	}
	s1[len + i] = '\0';
	return (s1);
}

static void	ri_appendline(t_read *result, char *buf, int ret)
{
	char	*temp;

	if (result->current_size + ret >= result->max_size)
	{
		result->max_size = result->max_size * 2;
		temp = ft_strnew(result->max_size);
		temp = ft_strcpy(temp, result->str);
		free(result->str);
		result->str = temp;
	}
	result->str = ft_strcat_e(result->str, buf, result->current_size);
	result->current_size = result->current_size + ret;
}

static char	*ri_read(int fd)
{
	t_read	result;
	int		ret;
	char	*buf;

	result.str = ft_strnew(BUFF_SIZE);
	result.current_size = 0;
	result.max_size = BUFF_SIZE;
	buf = ft_strnew(BUFF_SIZE);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 1)
	{
		ri_appendline(&result, buf, ret);
		ft_bzero(buf, ret);
	}
	return (result.str);
}

int			read_in(int fd, char **line)
{
	if (fd < 0 || !line)
		return (-1);
	*line = ri_read(fd);
	return (0);
}
