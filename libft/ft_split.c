/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkaram <alkaram@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 19:08:56 by alkaram           #+#    #+#             */
/*   Updated: 2024/03/15 02:16:17 by alkaram          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*get_word(char const *s, char c, int *start)
{
	int		i;
	int		start_pos;
	char	*word;

	if (!s)
		return (NULL);
	i = *start;
	start_pos = *start;
	while (s[i])
	{
		if ((s[i] != c) && (i == 0 || s[i - 1] == c))
			start_pos = i;
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			word = malloc(i - start_pos + 2);
			if (!word)
				return (NULL);
			ft_strlcpy(word, s + start_pos, i - start_pos + 2);
			word[i - start_pos + 1] = '\0';
			*start = i + 1;
			return (word);
		}
		i++;
	}
	return (NULL);
}

static int	count_words(char const *s, char c)
{
	int	i;
	int	w_count;

	if (!s)
		return (0);
	i = 1;
	w_count = 0;
	if (s[0] != c && s[0])
		w_count++;
	if (ft_strlen(s) == 0)
		return (0);
	while (s[i])
	{
		if (s[i] != c && s[i - 1] == c)
			w_count++;
		i++;
	}
	return (w_count);
}

char	*safe_free(char **result, int i)
{
	while (i >= 0)
	{
		free(result[i]);
		i--;
	}
	free(result);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		w_count;
	int		i;
	int		start;

	if (!s)
		return (NULL);
	start = 0;
	i = 0;
	w_count = count_words(s, c);
	result = malloc((w_count + 1) * sizeof(char *));
	if (result == NULL)
		return (NULL);
	while (i < w_count)
	{
		result[i] = get_word(s, c, &start);
		if (result[i] == NULL)
		{
			safe_free(result, i);
			return (NULL);
		}
		i++;
	}
	result[i] = NULL;
	return (result);
}

void	print_str_array(char **array)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
	{
		printf("%s\n", array[i]);
		i++;
	}
}

// int	main(void)
// {
// 	const char *input = ", , , , ,";
// 	print_str_array(ft_split(input, ','));
// 	return (0);
// }