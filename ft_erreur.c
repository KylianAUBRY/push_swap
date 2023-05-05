/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_erreur.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaubry <kyaubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 07:36:35 by kyaubry           #+#    #+#             */
/*   Updated: 2023/05/04 16:04:51 by kyaubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list(t_list *list1, t_list *list2)
{
	void	*test;

	if (list1 != NULL)
	{
		while (list1->next != NULL)
		{
			test = list1->next;
			free(list1);
			list1 = test;
		}
		free(list1);
	}
	if (list2 != NULL)
	{
		while (list2->next != NULL)
		{
			test = list2->next;
			free(list2);
			list2 = test;
		}
		free(list2);
	}
}

void	free_list1(t_list *list1)
{
	void	*test;

	if (list1 != NULL)
	{
		while (list1->next != NULL)
		{
			test = list1->next;
			free(list1);
			list1 = test;
		}
		free(list1);
	}
}

int	erreur_double(t_list *list)
{
	void	*test;

	while (list->next != NULL)
	{
		test = list->next;
		free(list);
		list = test;
	}
	free(list);
	ft_putstr_zero("Error\n");
	return (0);
}

int	erreur_int(t_list *list)
{
	void	*test;

	while (list->next != NULL)
	{
		test = list->next;
		free(list);
		list = test;
	}
	free(list);
	ft_putstr_zero("Error\n");
	return (0);
}
