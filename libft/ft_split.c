/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eanastas <eanastas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 01:13:39 by eanastas          #+#    #+#             */
/*   Updated: 2021/12/31 18:54:57 by eanastas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		c_count(char const *s, char c);
static char		**mal_pointers(int count);
static char		**mal_words(int count, char **words, char *s, char c);
static void		add_words(int count, char **words, char *s, char c);

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		count;
	char	**words;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	count = c_count((char *)s, c);
	if (count == 0)
	{
		words = (char **)malloc(sizeof(char *));
		words[0] = NULL;
		return (words);
	}
	words = mal_pointers(count);
	words = mal_words(count, words, (char *)s, c);
	add_words(count, words, (char *)s, c);
	return (words);
}

static int	c_count(char const *s, char c)
{
	int	count;
	int	i;
	int	flag;

	count = 0;
	i = 0;
	flag = 1;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			if (flag == 1)
				count++;
			flag = 0;
		}
		else
			flag = 1;
		i++;
	}
	return (count);
}

static char	**mal_pointers(int count)
{
	char	**words;

	words = (char **)malloc((count + 1) * sizeof(char *));
	if (!words)
		return (NULL);
	words[count] = NULL;
	return (words);
}

static char	**mal_words(int count, char **words, char *s, char c)
{
	int	i;
	int	len;
	int	j;

	i = 0;
	len = 0;
	j = 0;
	while (j < count)
	{
		if (s[i] != c && s[i] != '\0')
			len++;
		else
		{
			if (len != 0 && (s[i] == c || s[i] == '\0'))
			{
				words[j] = (char *)malloc((len + 1) * sizeof(char));
				if (!words[j])
					return (NULL);
				j++;
				len = 0;
			}
		}
		i++;
	}
	return (words);
}

static void	add_words(int count, char **words, char *s, char c)
{
	int	i;
	int	len;
	int	j;

	i = 0;
	j = 0;
	len = 0;
	while (j < count)
	{
		if (s[i] != c && s[i] != '\0')
		{
			words[j][len] = s[i];
			len++;
		}
		else
		{
			if (len != 0 && (s[i] == c || s[i] == '\0'))
			{
				words[j][len] = '\0';
				j++;
				len = 0;
			}
		}
		i++;
	}
}
