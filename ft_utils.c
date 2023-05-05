/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaubry <kyaubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 05:28:21 by kyaubry           #+#    #+#             */
/*   Updated: 2023/05/02 12:56:55 by kyaubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_bit(int num, int bit)
{
	return ((num >> bit) & 1);
}

int	ft_putstr(char *dest)
{
	int	i;

	i = 0;
	while (dest[i])
	{
		write(1, &dest[i], 1);
		i++;
	}
	return (i);
}

int	ft_putstr_zero(char *dest)
{
	int	i;

	i = 0;
	while (dest[i])
	{
		write(2, &dest[i], 1);
		i++;
	}
	return (0);
}

long long int	ft_atoi_modif(const char *nptr)
{
	int				i;
	int				neg;
	long long int	nb;

	i = 0;
	neg = 1;
	nb = 0;
	while (((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ') && nptr[i])
		i++;
	if ((nptr[i] == '+' || nptr[i] == '-') && nptr[i])
	{
		if (nptr[i] == '-')
			neg *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9' && nptr[i])
	{
		nb = (nb * 10) + (nptr[i] - '0');
		i++;
	}
	return (neg * nb);
}

int	compt_list(t_list *list)
{
	int		i;
	t_list	*temp;

	i = 0;
	temp = list;
	if (temp != NULL)
	{
		i++;
		while (temp->next != NULL)
		{
			temp = temp->next;
			i++;
		}
	}
	return (i);
}
