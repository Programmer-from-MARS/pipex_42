/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eanastas <eanastas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 01:13:51 by eanastas          #+#    #+#             */
/*   Updated: 2021/12/31 18:55:00 by eanastas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	char	*joined;
	int		i;
	int		m;

	i = 0;
	m = 0;
	len = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	joined = (char *)malloc((len + 1) * sizeof(char));
	if (!joined)
		return (NULL);
	while (s1[i] != '\0')
	{
		joined[i] = s1[i];
		++i;
	}
	while (s2[m] != '\0')
	{
		joined[i] = s2[m];
		++i;
		++m;
	}
	joined[i] = '\0';
	return (joined);
}
