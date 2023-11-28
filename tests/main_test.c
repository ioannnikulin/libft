/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:00:01 by inikulin          #+#    #+#             */
/*   Updated: 2023/11/28 19:02:17 by inikulin         ###   ########.fr       */
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

int	a9(void)
{
	return printf("hello%#0+3.4d world\n", 12435);
}

int	b9(void)
{
	return ft_printf("hello%#0+3.4d world\n", 12435);
}

int tst_g = 0;

int	a10(void)
{
	return printf("hello%##0+3.4p world\n", &tst_g);
}

int	b10(void)
{
	return ft_printf("hello%##0+3.4p world\n", &tst_g);
}

int	a11(void)
{
	return printf("hel%%lo%-# 0+4.3p world\n", 12435);
}

int	b11(void)
{
	return ft_printf("hel%%lo%-# 0+4.3p world\n", 12435);
}

int	a12(void)
{
	return printf("hel%%lo%-# -0+-4.3u world\n", 12435);
}

int	b12(void)
{
	return ft_printf("hel%%lo%-# -0+-4.3u world\n", 12435);
}

int	a13(void)
{
	return printf("hel%%lo%-# -0+-4.3x world\n", 12445);
}

int	b13(void)
{
	return ft_printf("hel%%lo%-# -0+-4.3x world\n", 12445);
}

int	a14(void)
{
	return printf("hel%%lo% 3.4u world\n", 12435);
}

int	b14(void)
{
	return ft_printf("hel%%lo% 3.4u world\n", 12435);
}

int	a15(void)
{
	return printf("hel%%lo% 3.4X world\n", 12445);
}

int	b15(void)
{
	return ft_printf("hel%%lo% 3.4X world\n", 12445);
}

int	a16(void)
{
	return printf("hel%%lo%## 3.4X world\n", 1);
}

int	b16(void)
{
	return ft_printf("hel%%lo%## 3.4X world\n", 1);
}

int	a17(void)
{
	return printf("hel%%lo%##-0 3.4p world\n", &tst_g);
}

int	b17(void)
{
	return ft_printf("hel%%lo%##-0 3.4p world\n", &tst_g);
}

int	a18(void)
{
	return printf("hel%%lo%+4.3p world\n", &tst_g);
}

int	b18(void)
{
	return ft_printf("hel%%lo%+4.3p world\n", &tst_g);
}

int	a19(void)
{
	return printf("hel%%lo%## 13.14X world\n", 12445);
}

int	b19(void)
{
	return ft_printf("hel%%lo%## 13.14X world\n", 12445);
}

int	a20(void)
{
	return printf("hel%%lo%5.0X world\n", 0);
}

int	b20(void)
{
	return ft_printf("hel%%lo%5.0X world\n", 0);
}

int	a21(void)
{
	return printf("hel%%lo%5.0i world\n", 0);
}

int	b21(void)
{
	return ft_printf("hel%%lo%5.0i world\n", 0);
}

int	a22(void)
{
	return printf("hel%%lo%#.0X world\n", 0);
}

int	b22(void)
{
	return ft_printf("hel%%lo%#.0X world\n", 0);
}

int	a23(void)
{
	return printf("hel%%lo%#.0i world\n", 0);
}

int	b23(void)
{
	return ft_printf("hel%%lo%#.0i world\n", 0);
}

#define SZ 24

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
	as[9] = a9;
	bs[9] = b9;
	as[10] = a10;
	bs[10] = b10;
	as[11] = a11;
	bs[11] = b11;
	as[12] = a12;
	bs[12] = b12;
	as[13] = a13;
	bs[13] = b13;
	as[14] = a14;
	bs[14] = b14;
	as[15] = a15;
	bs[15] = b15;
	as[16] = a16;
	bs[16] = b16;
	as[17] = a17;
	bs[17] = b17;
	as[18] = a18;
	bs[18] = b18;
	as[19] = a19;
	bs[19] = b19;
	as[20] = a20;
	bs[20] = b20;
	as[21] = a21;
	bs[21] = b21;
	as[22] = a22;
	bs[22] = b22;
	as[23] = a23;
	bs[23] = b23;


	for (int i = 0; i < SZ; i ++)
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

