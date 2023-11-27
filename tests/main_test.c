/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:00:01 by inikulin          #+#    #+#             */
/*   Updated: 2023/11/27 15:25:27 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <assert.h>
#include "libft.h"
#include "ft_printf.h"

int	catch(char* fname)
{
	int out = open(fname, O_RDWR|O_CREAT|O_APPEND, 0600);
	if (-1 == out) { perror("opening file"); return 255; }
	int save = dup(fileno(stdout));
	if (-1 == dup2(out, fileno(stdout)))
       	{
	       	perror("cannot redirect stdout");
	       	return 255;
	}
	return (save);
}

void	finally(int out)
{
	fflush(stdout);
       	close(out);
	dup2(out, fileno(stdout));
	close(out);
}

#define SZ 2

int	a0(void)
{
	return printf("hello world\n");
}

int	b0(void)
{
	return ft_printf("hello world\n");
}

int	a1(void)
{
	return printf("hello%c world\n", '@');
}

int	b1(void)
{
	return ft_printf("hello%c world\n", '@');
}

int	main(void)
{
	int fs;
	int fc;
	char rs = 0, rc = 0;
	int rets, retc;
	int (*as[SZ])();
	int (*bs[SZ])();
	remove("std.tmp");
	remove("custom.tmp");
	as[0] = a0;
	bs[0] = b0;
	as[1] = a1;
	bs[1] = b1;

	for (int i = 0; i < SZ; i ++)
	{
		fs = catch("std.tmp");
		rets = as[i]();
		finally(fs);
		fc = catch("custom.tmp");
		retc = bs[i]();
		finally(fc);
		assert(rets == retc);
		fs = open("std.tmp", O_RDONLY, 0600);
		fc = open("custom.tmp", O_RDONLY, 0600);
		rs = 1;
		rc = 1;
		while (!rs)
		{
			read(fs, &rs, 1);
			read(fc, &rc, 1);
			assert(!rc && rs == rc);
		}
		close(fs);
		close(fc);
	}
	return (0);
}

