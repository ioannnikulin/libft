/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:00:01 by inikulin          #+#    #+#             */
/*   Updated: 2023/11/27 18:59:47 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <assert.h>
#include "libft.h"
#include "ft_printf.h"
#define DEBUG

static void	catch(char* fname, int *out, int *save)
{
	remove(fname);
	fflush(stdout);
	*out = open(fname, O_RDWR|O_CREAT, 0600);
	assert (-1 != *out);
	*save = dup(fileno(stdout));
	assert (-1 != dup2(*out, fileno(stdout)));
}

void	finally(int *out, int *save)
{
	fflush(stdout);
       	close(*out);
	dup2(*save, fileno(stdout));
	close(*out);
}

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

int	a2(void)
{
	return printf("hello%s world\n", "qwe#\0\noo");
}

int	b2(void)
{
	return ft_printf("hello%s world\n", "qwe#\0\noo");
}

int	a3(void)
{
	return printf("hello%-# +11s world\n", "qwe#\0\noo");
}

int	b3(void)
{
	return ft_printf("hello%-# +11s world\n", "qwe#\0\noo");
}

int	a4(void)
{
	return printf("hello%-0# +11s world\n", "qwiiiiiiiiiiiiiie#\0\noo");
}

int	b4(void)
{
	return ft_printf("hello%-0# +11s world\n", "qwiiiiiiiiiiiiiie#\0\noo");
}

int	a5(void)
{
	return printf("hello%3.4s world\n", "qwiiiiiiiiiiiiiie#\0\noo");
}

int	b5(void)
{
	return ft_printf("hello%3.4s world\n", "qwiiiiiiiiiiiiiie#\0\noo");
}

int	a6(void)
{
	return printf("hello%4.3s world\n", "qwiiiiiiiiiiiiiie#\0\noo");
}

int	b6(void)
{
	return ft_printf("hello%4.3s world\n", "qwiiiiiiiiiiiiiie#\0\noo");
}

int	a7(void)
{
	return printf("hello%-# 0+4.3i world\n", 12435);
}

int	b7(void)
{
	return ft_printf("hello%-# 0+4.3i world\n", 12435);
}

int	a8(void)
{
	return printf("hello%-# 0+3.4i world\n", 12435);
}

int	b8(void)
{
	return ft_printf("hello%-# 0+3.4i world\n", 12435);
}

#define SZ 9

int	main(void)
{
	int fs;
	int fc;
	int out, save;
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
	as[2] = a2;
	bs[2] = b2;
	as[3] = a3;
	bs[3] = b3;
	as[4] = a4;
	bs[4] = b4;
	as[5] = a5;
	bs[5] = b5;
	as[6] = a6;
	bs[6] = b6;
	as[7] = a7;
	bs[7] = b7;
	as[8] = a8;
	bs[8] = b8;

	for (int i = 7; i < SZ; i ++)
	{
#ifdef DEBUG
		printf("%i\n", i);
#endif
		catch("std.tmp", &out, &save);
		rets = as[i]();
		finally(&out, &save);
		catch("custom.tmp", &out, &save);
		retc = bs[i]();
		finally(&out, &save);
#ifdef DEBUG
		printf("%i %i\n", rets, retc);
#endif
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

