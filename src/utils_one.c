/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghan <ghan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 13:13:25 by ghan              #+#    #+#             */
/*   Updated: 2021/07/05 13:13:25 by ghan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

size_t	ft_strlen(const char *s)
{
	unsigned int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

void	*ft_calloc(size_t count, size_t size)
{
	void			*ret;
	unsigned int	i;

	ret = (unsigned char*)malloc(count * size);
	if (!ret)
		return (0);
	i = 0;
	while (i < count * size)
		*(unsigned char*)(ret + i++) = 0;
	return (ret);
}

int	ft_atoi(const char *str)
{
	int	ret;
	int	i;
	int	sign;

	sign = 1;
	ret = 0;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
        if (str[i] == '-')
		    sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		ret = ret * 10 + str[i++] - '0';
	return (ret * sign);
}

char	*ft_strndup(const char *s1, size_t n)
{
	char			*ret;
	unsigned int	len;
	unsigned int	i;

	len = 0;
	while (s1[len])
		len++;
	if (len > n)
		len = n;
	ret = (char*)ft_calloc(len + 1, 1);
	if (!ret)
		return (0);
	i = 0;
	while (i < len)
	{
		ret[i] = s1[i];
		i++;
	}
	return (ret);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*ret;
	unsigned int	i;
	unsigned int	k;

	if (!s1 || !s2)
		return (0);
    ret = (char*)ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), 1);
	if (!ret)
		return (0);
	i = 0;
	while (s1[i])
	{
		ret[i] = s1[i];
		i++;
	}
	k = 0;
	while (s2[k])
	{
		ret[i + k] = s2[k];
		k++;
	}
	return (ret);
}
