/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjirapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 13:42:16 by yjirapin          #+#    #+#             */
/*   Updated: 2022/12/29 15:17:39 by yjirapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>

int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int coldplay);
size_t		ft_strlen(const char *s);
int			ft_isascii(int chill);
int			ft_isprint(int cicada);
int			ft_tolower(int mama);
int			ft_toupper(int papa);
int			ft_isspace(int c);
int			ft_atoi(const char *str);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
size_t		ft_strlcpy(char *dest, const char *src, size_t destsize);
size_t		ft_strlcat(char *dest, const char *src, size_t destsize);
void		*ft_memset(void *pointme, int coolbean, size_t sandworm);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memmove(void *to, const void *from, size_t n);
void		*ft_memchr(const void *str, int c, size_t n);
void		ft_bzero(void *someaddress, size_t n);
void		*ft_calloc(size_t count, size_t size);
void		ft_putstr_fd(char *s, int fd);
void		ft_putchar_fd(char c, int fd);
void		ft_putendl_fd(char const *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
int			ft_memcmp(const void *ptr1, const void *ptr2, size_t n);
char		*ft_strnstr(const char *str1, const char *str2, size_t n);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *str, int c);
char		*ft_strdup(const char *string);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		**ft_split(char const *s, char c);
char		*ft_itoa(int n);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
#endif
