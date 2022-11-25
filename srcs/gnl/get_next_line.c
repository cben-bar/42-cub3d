/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cben-bar <cben-bar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 01:48:16 by cben-bar          #+#    #+#             */
/*   Updated: 2022/10/20 19:16:35 by cben-bar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

static void	ft_switch(char **s, char *buffer)
{
	char	*tmp;

	if (*s)
	{
		tmp = *s;
		*s = ft_strjoin(tmp, buffer);
		free(tmp);
		return ;
	}
	*s = ft_strdup(buffer);
}

static char	*ft_dispatch(char **s)
{
	char	*tmp;
	char	*displayed_line;

	tmp = *s;
	*s = ft_strdup(ft_strchr(tmp, '\n') + 1);
	displayed_line = ft_strndup(tmp, ft_strlen(tmp) - ft_strlen(*s));
	free(tmp);
	return (displayed_line);
}

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	static char	*s = NULL;
	int			rvr;
	char		*tmp;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE < 1)
		return (NULL);
	rvr = 1;
	while (rvr > 0)
	{
		rvr = read(fd, buffer, BUFFER_SIZE);
		if ((rvr == -1) || (rvr == 0 && s == NULL))
			return (NULL);
		buffer[rvr] = '\0';
		ft_switch(&s, buffer);
		if (ft_strchr(s, '\n'))
			return (ft_dispatch(&s));
	}
	if (s && !s[0])
		tmp = NULL;
	else
		tmp = ft_strdup(s);
	free(s);
	s = NULL;
	return (tmp);
}
