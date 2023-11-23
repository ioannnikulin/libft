/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 20:24:25 by inikulin          #+#    #+#             */
/*   Updated: 2023/11/23 15:54:02 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	count_words(const char *pp, char c)
{
	int		word_qtty;
	char	*p;

	word_qtty = 0;
	p = (char *)pp;
	while (p && *p)
	{
		if (*p == c)
		{
			if (word_qtty > 0)
				word_qtty = -word_qtty;
		}
		else
		{
			if (word_qtty <= 0)
				word_qtty = -word_qtty + 1;
		}
		p ++;
	}
	if (word_qtty < 0)
		return (-word_qtty);
	return (word_qtty);
}

static void	parse_word(char **res, const char **f, char c)
{
	int		cwlen;
	char	**from;

	from = (char **)f;
	while (**from && **from == c)
		(*from)++;
	cwlen = 0;
	while ((*from)[cwlen] && (*from)[cwlen] != c)
		cwlen ++;
	if (cwlen == 0)
		return ;
	(*res) = (char *) malloc((cwlen + 1) * sizeof(char));
	if (*res == 0)
		return ;
	cwlen = 0;
	while (**from && **from != c)
	{
		(*res)[cwlen ++] = **from;
		(*from)++;
	}
	(*res)[cwlen] = 0;
}

static int	check_edges(char **res, int *cwi)
{
	if (!res[*cwi])
	{
		while (-- (*cwi) > -1)
			free(res[*cwi]);
		free(res);
		return (1);
	}
	if (!res[*cwi][0])
	{
		free(res[*cwi]);
		(*cwi)--;
	}
	return (0);
}

char	**ft_split(const char *str, char c)
{
	char	**res;
	int		word_qtty;
	int		cwi;

	word_qtty = count_words(str, c);
	res = (char **) malloc((word_qtty + 1) * sizeof(char *));
	if (res == 0)
		return (0);
	res[word_qtty] = 0;
	if (word_qtty == 0)
		return (res);
	cwi = 0;
	while (*str && cwi < word_qtty)
	{
		parse_word(&res[cwi], &str, c);
		if (check_edges(res, &cwi))
			return (0);
		cwi ++;
	}
	return (res);
}
