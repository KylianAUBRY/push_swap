/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaubry <kyaubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 05:35:40 by kyaubry           #+#    #+#             */
/*   Updated: 2023/05/05 12:09:35 by kyaubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_split(char *s, t_list **list)
{
	t_list			*temp;
	int				i;
	long long int	nb;

	i = 0;
	temp = *list;
	if (s == NULL)
		return (0);
	while (s[i] != '\0')
	{
		while (temp->next != NULL)
			temp = temp->next;
		while (s[i] && s[i] == ' ')
			i++;
		nb = ft_atoi_modif(s + i);
		if (nb > 2147483647 || nb < -2147483648 || verif_char(s + i) == 0)
			return (erreur_int(*list));
		temp->next = ft_add_node_end(nb);
		while (s[i] && s[i] != ' ')
			i++;
	}
	return (1);
}
