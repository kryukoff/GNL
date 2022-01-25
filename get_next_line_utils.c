/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmolina <lmolina@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 21:38:08 by lmolina           #+#    #+#             */
/*   Updated: 2022/01/25 19:06:02 by lmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(char *s1)
{
	char	*s2;

	s2 = (char *) malloc (ft_strlen(s1) + 1);
	if (s2 != 0)
		ft_memcpy(s2, s1, (ft_strlen(s1) + 1));
	return (s2);
}

char	*ft_strdup_n(char *s1, int n)
{
	char	*s2;
	if ((int)ft_strlen(s1) < n)
		return (0);
	s2 = (char *) malloc (n + 1);
	if (s2 != 0)
		ft_memcpy(s2, s1, (n));
	s2[n] = '\0';
	return (s2);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	char	*ret_str;

	if (s2 == 0 || s1 == 0)
		return (0);
	i = 0;
	ret_str = (char *) malloc (ft_strlen(s1) + ft_strlen(s2) + 1);
	if (ret_str == 0)
		return (0);
	while (*s1 != '\0')
		ret_str[i++] = *s1++;
	while (*s2 != '\0')
		ret_str[i++] = *s2++;
	ret_str[i] = '\0';
	return (ret_str);
}

size_t	ft_strlen(char *s)
{
	size_t	lenght;

	lenght = 0;
	while (s[lenght] != '\0')
		lenght++;
	return (lenght);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*loc_dst;
	const unsigned char	*loc_src;

	if ((dst == src) || n == 0)
		return (dst);
	if ((dst == '\0') && (src == '\0'))
		return (0);
	loc_dst = (unsigned char *) dst;
	loc_src = (const unsigned char *) src;
	while (n > 0)
	{
		n--;
		loc_dst[n] = loc_src[n];
	}
	dst = (unsigned char *) loc_dst;
	return (dst);
}

char	*ft_strchr(char	*s, int c)
{
	size_t	i;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return ((char *) &s[i]);
		i++;
	}
	return (0);
}
