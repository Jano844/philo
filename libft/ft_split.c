/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanger <jsanger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 09:05:22 by jsanger           #+#    #+#             */
/*   Updated: 2023/04/03 18:36:54 by jsanger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *s, char c)
{
	int	i;
	int	j;
	int	l;

	j = 0;
	l = 0;
	i = 0;
	while (s[i] == c && s[i] != '\0')
		i++;
	if ((size_t)i == ft_strlen(s))
		return (0);
	while (s[j] == c)
		j++;
	while (s[j] != '\0')
	{
		if (s[j] == c && s[j + 1] != c && s[j + 1] != '\0')
			l++;
		j++;
	}
	return (l + 1);
}

static int	ft_word_length(char const *s, char c, int i)
{
	int	size;

	size = 0;
	while (s[i] != c && s[i])
	{
		size++;
		i++;
	}
	return (size);
}

static void	ft_free(char **strs, int j)
{
	while (j-- > 0)
		free(strs[j]);
	free(strs);
}

static char	**ft_allocate(int i, int j, char const *s, char c)
{
	char	**strings;
	int		length;

	if (!s)
		return (NULL);
	strings = ft_calloc((ft_count_words(s, c) + 1), sizeof(char *));
	if (strings == 0)
		return (NULL);
	while (++j < ft_count_words(s, c))
	{
		while (s[i] == c)
			i++;
		length = ft_word_length(s, c, i);
		strings[j] = ft_substr(s, i, length);
		if (strings[j] == 0)
		{
			ft_free(strings, j);
			return (NULL);
		}
		i += length;
	}
	strings[j] = NULL;
	return (strings);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**strs;

	i = 0;
	j = -1;
	strs = ft_allocate(i, j, s, c);
	return (strs);
}

// int	main(void)
// {
// 	char	s[] = "split  ||this|for|me|||||!|!";
// 	char	c;

// 	c = '|';
// 	ft_split(s, c);
// 	return (0);
// }
