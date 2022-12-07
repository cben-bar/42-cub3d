/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manipulation_string.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cben-bar <cben-bar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 17:15:40 by cben-bar          #+#    #+#             */
/*   Updated: 2022/12/07 14:35:09 by cben-bar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

char	*ft_cjoin(const char *s1, char s2)
{
	char	*joined;
	size_t	len;
	size_t	i;

	i = -1;
	len = ft_strlen(s1) + 1;
	joined = malloc(sizeof(char) * (len + 1));
	if (!joined)
		return (NULL);
	while (s1[++i])
		joined[i] = s1[i];
	joined[i + 1] = s2;
	joined[len] = '\0';
	return (joined);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strcpy(char *dst, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

int	ft_atoi(const char *str, t_data *data)
{
	long	i;
	int		maybe_neg;
	int		res;

	i = 0;
	maybe_neg = 1;
	res = 0;
	if (str == NULL || str[0] == '\0')
		free_and_quit("Invalid rgb line", data);
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == ' '))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			maybe_neg *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * maybe_neg);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
