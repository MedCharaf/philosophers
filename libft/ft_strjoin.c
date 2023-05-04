/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouderr <mbouderr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 02:58:48 by mbouderr          #+#    #+#             */
/*   Updated: 2023/04/28 21:30:01 by mbouderr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	char	*p;
	size_t	len_s1;
	size_t	len_s2;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	i = 0;
	p = (char *)ft_calloc(((len_s1 + len_s2) + 1), sizeof(char));
	if (p == NULL)
		return (NULL);
	while (i < len_s1)
	{
		p[i] = s1[i];
		i++;
	}
	i = 0;
	while (i <= len_s2)
	{
		p[i + len_s1] = s2[i];
		i++;
	}
	free(s1);
	return (p);
}
