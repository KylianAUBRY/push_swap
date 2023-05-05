/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaubry <kyaubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 09:09:24 by kyaubry           #+#    #+#             */
/*   Updated: 2023/05/01 11:47:24 by kyaubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_list *list1)
{
	t_list	*temp;
	t_list	*temp2;
	int		t;

	temp = list1;
	temp2 = list1->next;
	if (temp->next != NULL)
	{
		t = temp->data;
		temp->data = temp2->data;
		temp2->data = t;
	}
	ft_putstr("sa\n");
}

void	ft_sb(t_list *list2)
{
	t_list	*temp;
	t_list	*temp2;
	int		t;

	temp = list2;
	temp2 = list2->next;
	if (temp->next != NULL)
	{
		t = temp->data;
		temp->data = temp2->data;
		temp2->data = t;
	}
	ft_putstr("sb\n");
}

void	ft_ss(t_list *list, t_list *list2)
{
	t_list	*temp;
	t_list	*temp2;
	int		t;

	temp = list;
	temp2 = list->next;
	if (temp->next != NULL)
	{
		t = temp->data;
		temp->data = temp2->data;
		temp2->data = t;
	}
	temp = list2;
	temp2 = list2->next;
	if (temp->next != NULL)
	{
		t = temp->data;
		temp->data = temp2->data;
		temp2->data = t;
	}
	ft_putstr("ss\n");
}

void	ft_pa(t_list **list1, t_list **list2)
{
	t_list	*temp;
	t_list	*temp2;

	temp2 = *list2;
	if (*list2 != NULL)
	{
		temp = malloc(sizeof(t_list));
		temp->data = temp2->data;
		temp->next = *list1;
		*list1 = temp;
		*list2 = delete_first_node(*list2);
	}
	ft_putstr("pa\n");
}

void	ft_pb(t_list **list1, t_list **list2)
{
	t_list	*temp;
	t_list	*temp2;

	temp2 = *list1;
	if (*list1 != NULL)
	{
		temp = malloc(sizeof(t_list));
		temp->data = temp2->data;
		temp->next = *list2;
		*list2 = temp;
		*list1 = delete_first_node(*list1);
	}
	ft_putstr("pb\n");
}
