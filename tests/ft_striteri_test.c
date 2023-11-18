/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:56:31 by inikulin          #+#    #+#             */
/*   Updated: 2023/11/18 14:40:41 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
//#define DEBUG

typedef struct s_testcase
{
	char	what[20];
	void	(*f)(unsigned int, char *);
	char	*res;
	char	nullify;
}	t_testcase;

#define SZ 11

static void	a(unsigned int idx, char *c)
{
	if (idx % 2 == 0)
		*c = '_';
	*c = (*c) - 1;
}

static void	b(unsigned int idx, char *c)
{
	(void)idx;
	if (ft_isalpha(*c))
		*c = 'a';
	if (ft_isdigit(*c))
		*c = '0';
	if (ft_isspace(*c))
		*c = ' ';
	*c = '.';
}

void	ft_striteri_test(void)
{
	t_testcase t[SZ];
	t[0] = (t_testcase){"abc", a, "_a_", 0};
	t[1] = (t_testcase){"", a, "", 0};
	t[2] = (t_testcase){"@!@#723gfd\t\n", a, "_ _\"_1_f_c_\t", 0};
	t[3] = (t_testcase){"i\x7F\x01r", a, "_\x7E_q", 0};
	t[4] = (t_testcase){"abc", b, "aaa", 0};
	t[5] = (t_testcase){"", b, "", 0};
	t[6] = (t_testcase){"@!@#723gfd\t\n", b, "....000aaa  ", 0};
	t[7] = (t_testcase){"i\x7F\x01r", b, "a..a", 0};
	t[8] = (t_testcase){"abc", a, 0, 1};
	t[9] = (t_testcase){"abc", a, 0, 2};
	t[10] = (t_testcase){"abc", a, 0, 3};
	for (int i = 0; i < SZ; i ++)
	{
		ft_striteri(
				((t[i].nullify & 1) > 0 ? NULL : t[i].what)
				,((t[i].nullify & 2) > 0 ? NULL : t[i].f)
			);
		#ifdef DEBUG
		printf("%i [%s][%s]\n", i, res, t[i].res);
		#endif
		assert(strcmp(t[i].what, t[i].res) == 0);
	}
}
