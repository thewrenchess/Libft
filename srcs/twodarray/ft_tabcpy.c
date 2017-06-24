/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yherrera <yherrera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/24 12:24:43 by yherrera          #+#    #+#             */
/*   Updated: 2017/06/24 15:17:56 by yherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdrs/libft.h"

char	**ft_tabcpy(char **dst, char **src)
{
	size_t	i;

	if (!dst || !src)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dst[i] = ft_strdup(src[i]);
		i++;
	}
	return (dst);
}
