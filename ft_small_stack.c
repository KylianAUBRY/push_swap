/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_small_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaubry <kyaubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 02:19:01 by kyaubry           #+#    #+#             */
/*   Updated: 2023/05/02 07:43:51 by kyaubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_three(t_list **list)
{
	t_list	*temp;
	int		i;
	int		i2;
	int		i3;

	temp = *list;
	i = temp->data;
	temp = temp->next;
	i2 = temp->data;
	temp = temp->next;
	i3 = temp->data;
	if (i > i3 && i > i2)
	{
		ft_ra(list);
		if (i2 > i3)
			ft_sa(*list);
		return ;
	}
	if (i > i2)
		ft_sa(*list);
	if (i3 < i2 && i2 > i)
		ft_rra(list);
	if (i < i2 && i2 > i3 && i < i3)
		ft_sa(*list);
}

void	ft_mall_small(t_list **list, int count_list)
{
	t_list	*temp;
	int		i;

	if (count_list == 3)
	{
		ft_three(list);
		return ;
	}
	temp = *list;
	i = temp->data;
	temp = temp->next;
	if (i > temp->data)
		ft_sa(*list);
}

int	verif_first(t_list *list1)
{
	t_list	*temp;

	temp = list1;
	if (temp->data > temp->next->data && temp->data > temp->next->next->data
		&& temp->data > temp->next->next->next->data)
		return (1);
	if (temp->data < temp->next->data && temp->data < temp->next->next->data
		&& temp->data < temp->next->next->next->data)
		return (1);
	return (0);
}

void	ft_four(t_list **list1, t_list **list2)
{
	t_list	*temp;

	while (verif_first(*list1) != 1)
		ft_ra(list1);
	temp = *list1;
	ft_pb(list1, list2);
	ft_three(list1);
	ft_pa(list1, list2);
	temp = *list1;
	if (temp->data > temp->next->next->next->data)
		ft_ra(list1);
}

void	ft_five(t_list **list1, t_list **list2, int count_list)
{
	t_list	*temp;

	if (count_list == 4)
		return (ft_four(list1, list2));
	while (verif_first(*list1) != 1)
		ft_ra(list1);
	ft_pb(list1, list2);
	while (verif_first(*list1) != 1)
		ft_ra(list1);
	ft_pb(list1, list2);
	ft_three(list1);
	ft_pa(list1, list2);
	temp = *list1;
	if (temp->data > temp->next->next->next->data)
		ft_ra(list1);
	ft_pa(list1, list2);
	temp = *list1;
	if (temp->data > temp->next->next->next->data)
		ft_ra(list1);
}
