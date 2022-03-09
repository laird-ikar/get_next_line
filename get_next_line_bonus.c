/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 09:25:13 by bguyot            #+#    #+#             */
/*   Updated: 2022/03/09 07:14:59 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	t_gnl	gnl;

	gnl.ret = 1;
	gnl.i = 1;
	gnl.res = ft_calloc(1, 1);
	if (fd < 0 || BUFFER_SIZE < 1 || !gnl.res || read(fd, gnl.buff, 0) < 0)
	{
		if (gnl.res)
			free(gnl.res);
		return (NULL);
	}
	while (gnl.ret > 0 && gnl.buff[gnl.i - 1] != '\n')
	{
		gnl.i = 1;
		ft_bzero(gnl.buff, BUFFER_SIZE + 1);
		while (gnl.i < BUFFER_SIZE + 1
			&& gnl.buff[gnl.i - 1] != '\n' && gnl.ret > 0)
			gnl.ret = read(fd, gnl.buff + gnl.i++, 1);
		gnl.buff[gnl.i] = '\0';
		gnl.tmp = ft_strjoin(gnl.res, gnl.buff + 1);
		free(gnl.res);
		gnl.res = gnl.tmp;
	}
	return (return_value(gnl.res));
}

char	*return_value(char	*res)
{
	static int	uwu_bonus_pwease;

	(void) uwu_bonus_pwease;
	if (res[0] == '\0')
	{
		free(res);
		return (NULL);
	}
	return (res);
}
