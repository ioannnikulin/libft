/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:16:17 by inikulin          #+#    #+#             */
/*   Updated: 2024/01/13 13:00:05 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stddef.h>
# define LLTOA_BASE_MAX_LEN 65

// -------- symbols --------
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_isspace(int c);
int		ft_tolower(int c);
int		ft_toupper(int c);
// -------- strings --------
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strdup(char *s);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strtrim(const char *s1, const char *set);
char	**ft_split_set(const char *s, const char *charset);
char	**ft_split(const char *s, char delim);
char	*ft_strmapi(const char *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
int		ft_is_in(const char c, const char *set);
char	*ft_empty_string(void);
// -------- numbers <> strings --------
int		ft_atoi(const char *nptr);
char	*ft_itoa(int v);
size_t	ft_lltoa_base(long long nbr, char *base, char *buf);
size_t	ft_ulltoa_base(unsigned long long nbr, char *base, char *buf);
// -------- memory --------
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
int		ft_memcmp(const char *s1, const char *s2, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
// -------- lists --------
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
	struct s_list	*prev;
	unsigned char	type;
}	t_list;
// types:
// 0 single-linked, can be circular
// 1 double-linked, can be circular
t_list	*ft_lstnew(void *content);
t_list	*ft_lst_generate(char	*texts[], int end_to);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
// -------- printf --------
int		ft_printf(const char *s, ...);
int		ft_fprintf(int fd, const char *s, ...);
#endif
