/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraiha <sraiha@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 11:08:50 by sraiha            #+#    #+#             */
/*   Updated: 2024/11/07 12:26:06 by sraiha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_word_count(const char *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		if (*s != c)
		{
			++count;
			while (*s && *s != c)
				++s;
		}
		else
			++s;
	}
	return (count);
}

static size_t	ft_word_len(const char *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static void	ft_free_arr(char **arr, size_t words)
{
	size_t	i;

	i = 0;
	while (i < words)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

char	*one_word(const char **arr, char c)
{
	const char		*ptr;
	char			*new_word;
	size_t			wordlen;

	ptr = *arr;
	while (*ptr && *ptr == c)
		ptr++;
	wordlen = ft_word_len(ptr, c);
	new_word = (char *)malloc(sizeof(char) + (wordlen + 1));
	if (!new_word)
		return (NULL);
	ft_strlcpy(new_word, ptr, wordlen + 1);
	ptr += wordlen;
	*arr = ptr;
	return (new_word);
}

char	**ft_split(const char *s, char c)
{
	char		**words;
	size_t		i;
	size_t		count;

	count = ft_word_count(s, c);
	words = (char **)malloc(sizeof(char *) * (count + 1));
	if (!words)
		return (NULL);
	i = 0;
	while (i < count)
	{
		words[i] = one_word(&s, c);
		if (!words[i])
		{
			ft_free_arr(words, i);
			return (NULL);
		}
		i++;
	}	
	words[i] = NULL;
	return (words);
}
