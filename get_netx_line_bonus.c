/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 09:25:13 by bguyot            #+#    #+#             */
/*   Updated: 2022/02/25 09:47:30 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int		error_catch;
	char	*tmp;
	char	*res;
	char	buffer[BUFFER_SIZE + 1];
	int		i;

	error_catch = 1;
	i = 1;
	res = malloc(1);
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	while (error_catch && buffer[i - 1] != '\n')
	{
		i = 1;
		ft_bzero(buffer, BUFFER_SIZE + 1);
		while (i < BUFFER_SIZE + 1 && buffer[i - 1] != '\n' && error_catch)
			error_catch = read(fd, buffer + i++, 1);
		tmp = ft_strjoin(res, buffer + 1);
		free (res);
		res = tmp;
	}
	return (res);
}
