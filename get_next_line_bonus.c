/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 09:25:13 by bguyot            #+#    #+#             */
/*   Updated: 2022/02/26 20:56:39 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int		ret;
	char	*res;
	char	buff[BUFFER_SIZE + 2];
	int		i;

	ret = 1;
	i = 1;
	res = ft_calloc(1, 1);
	if (fd < 0 || BUFFER_SIZE < 1 || !res || read(fd, buff, 0) < 0)
		return (free_and_null(res));
	while (ret > 0 && buff[i - 1] != '\n')
	{
		i = 1;
		ft_bzero(buff, BUFFER_SIZE + 1);
		while (i < BUFFER_SIZE + 1
			&& buff[i - 1] != '\n' && ret > 0)
			ret = read(fd, buff + i++, 1);
		buff[i] = '\0';
		res = ft_strjoin(res, buff + 1);
	}
	if (res[0] == '\0')
		free_and_null(res);
	return (res);
}

void	*free_and_null(void *ptr)
{
	if (ptr)
		free(ptr);
	ptr = NULL;
	return (ptr);
}
