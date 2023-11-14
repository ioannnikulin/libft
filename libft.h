/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:16:17 by inikulin          #+#    #+#             */
/*   Updated: 2023/11/14 16:29:09 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

int	ft_isalpha(int);
int	ft_isdigit(int);
int	ft_isalnum(int);
int	ft_isascii(int);
int	ft_isprint(int);
unsigned long long	ft_strlen(char * s);
void	*ft_memset(void *s, int c, unsigned long long n);
void	*ft_bzero(void *s, unsigned long long n);
void	*ft_memcpy(void *dest, const void *src, unsigned long long n);
void	*ft_memmove(void *dest, const void *src, unsigned long long n);
#endif
