/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:56:43 by inikulin          #+#    #+#             */
/*   Updated: 2023/11/22 19:48:57 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
#define SZ 14
//#define DEBUG

typedef struct s_testcase
{
	int	end_to;
	void	*(*f)(void*);
	void	(*del)(void*);
	char	*texts[20];
	char	*res[20];
}	t_testcase;

void	*a(void *oc)
{
	return (ft_strdup((char*)oc));
}

void	*b(void *oc)
{
	if (ft_isdigit(((char*)oc)[0]))
		return (ft_strdup("0"));
	if (ft_isalpha(((char*)oc)[0]))
		return (ft_strdup("a"));
	return (ft_strdup("."));
}

void	ft_lstmap_test(void)
{
	t_testcase	t[SZ];
	t[0] = (t_testcase){-1, a, free, {"hello", "i", "", NULL}, {"hello", "i", "", NULL}};
	t[1] = (t_testcase){0, a, free, {"hello", "i", "", NULL}, {"hello", "i", "", NULL}};
	t[2] = (t_testcase){1, a, free, {"hello", "i", "", NULL}, {"hello", "i", "", NULL}};
	t[3] = (t_testcase){2, a, free, {"hello", "i", "", NULL}, {"hello", "i", "", NULL}};
	t[4] = (t_testcase){-1, a, free, {"hello", NULL}, {"hello", NULL}};
	t[5] = (t_testcase){0, a, free, {"hello", NULL}, {"hello", NULL}};
	t[6] = (t_testcase){-1, a, free, {NULL}, {NULL}};
	t[7] = (t_testcase){-1, a, free, {"hello", "i", "", NULL}, {"hello", "i", "", NULL}};
	t[8] = (t_testcase){0, a, free, {"hello", "i", "", NULL}, {"hello", "i", "", NULL}};
	t[9] = (t_testcase){1, a, free, {"hello", "i", "", NULL}, {"hello", "i", "", NULL}};
	t[10] = (t_testcase){2, a, free, {"hello", "i", "", NULL}, {"hello", "i", "", NULL}};
	t[11] = (t_testcase){-1, a, free, {"hello", NULL}, {"hello", NULL}};
	t[12] = (t_testcase){0, a, free, {"hello", NULL}, {"hello", NULL}};
	t[13] = (t_testcase){-1, a, free, {NULL}, {NULL}};
	for (int i = 0; i <  SZ; i ++)
	{
#ifdef DEBUG
		printf("%i ", i);
		fflush(stdout);
#endif
		t_list *src = ft_lst_generate(t[i].texts, t[i].end_to);
		t_list *n = ft_lstmap(src, t[i].f, t[i].del);
		t_list *loop_start = NULL;
#ifdef DEBUG
		ft_lst_print(n);
#endif
		for (int j = 0; t[i].texts[j] != NULL; j ++)
		{
			assert(n);
			assert(strcmp(n->content, t[i].texts[j]) == 0);
			if (t[i].end_to == j)
				loop_start = n;
			n = n->next;
		}
		assert((t[i].end_to == -1 && !n) || (t[i].end_to > -1 && n == loop_start));
		ft_lstclear(&src, free);
		ft_lstclear(&n, free);
	}
}
