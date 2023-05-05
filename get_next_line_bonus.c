/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaubry <kyaubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 11:24:36 by kyaubry           #+#    #+#             */
/*   Updated: 2023/05/02 12:02:09 by kyaubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	char		*dest;
	int			i;

	i = 1;
	dest = NULL;
	if (BUFFER_SIZE == 0 || fd < 0)
		return (0);
	if (ft_chr(buff) == 1)
	{
		ft_buf_cut(buff);
		dest = ft_join(dest, buff);
	}
	while (i > 0 && ft_chr(buff) == 0)
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i <= 0)
			return (dest);
		buff[i] = '\0';
		dest = ft_join(dest, buff);
	}
	return (dest);
}
