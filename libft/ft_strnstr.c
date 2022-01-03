/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eanastas <eanastas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 01:14:08 by eanastas          #+#    #+#             */
/*   Updated: 2021/12/31 18:55:05 by eanastas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	m_check(size_t m);

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t			i;
	size_t			m;
	unsigned char	*ret;

	i = 0;
	m = 0;
	if (ft_strlen(haystack) < ft_strlen(needle))
		return (NULL);
	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	while (haystack[i] != '\0' && len != 0)
	{
		if ((unsigned char)needle[m] == (unsigned char)haystack[i])
			m++;
		if (needle[m] == '\0')
		{
			ret = (unsigned char *)haystack + i - (m - 1);
			return ((char *)ret);
		}
		if ((unsigned char)needle[m - 1] != (unsigned char)haystack[i])
			m = m_check(m);
		i++;
		len--;
	}
	return (NULL);
}

static size_t	m_check(size_t m)
{
	if (m != 0)
		m = 1;
	else
		m = 0;
	return (m);
}
