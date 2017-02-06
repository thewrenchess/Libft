/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yherrera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 20:11:23 by yherrera          #+#    #+#             */
/*   Updated: 2017/02/05 20:11:47 by yherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdrs/libft.h"

size_t	ft_countline(char **tab)
{
	size_t	i;

	if (!tab)
		return (0);
	i = 0;
	while (tab[i])
		i++;
	return (i);
}
