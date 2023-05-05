/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaubry <kyaubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 11:40:37 by kyaubry           #+#    #+#             */
/*   Updated: 2023/05/02 11:42:05 by kyaubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra_bonus(t_list **list1)
{
	int		temp;
	t_list	*temp2;

	temp2 = *list1;
	if (*list1 != NULL)
	{
		temp = temp2->data;
		*list1 = delete_first_node(*list1);
		temp2 = *list1;
		while (temp2->next != NULL)
			temp2 = temp2->next;
		temp2->next = ft_add_node_end(temp);
	}
}

void	ft_rb_bonus(t_list **list2)
{
	int		temp;
	t_list	*temp2;

	temp2 = *list2;
	if (*list2 != NULL)
	{
		temp = temp2->data;
		*list2 = delete_first_node(*list2);
		temp2 = *list2;
		while (temp2->next != NULL)
			temp2 = temp2->next;
		temp2->next = ft_add_node_end(temp);
	}
}

void	ft_rr_bonus(t_list **list1, t_list **list2)
{
	int		temp;
	t_list	*temp2;

	temp2 = *list1;
	if (*list1 != NULL)
	{
		temp = temp2->data;
		*list1 = delete_first_node(*list1);
		temp2 = *list1;
		while (temp2->next != NULL)
			temp2 = temp2->next;
		temp2->next = ft_add_node_end(temp);
	}
	temp2 = *list2;
	if (*list2 != NULL)
	{
		temp = temp2->data;
		*list2 = delete_first_node(*list2);
		temp2 = *list2;
		while (temp2->next != NULL)
			temp2 = temp2->next;
		temp2->next = ft_add_node_end(temp);
	}
}

void	ft_rra_bonus(t_list **list1)
{
	t_list	*temp;
	t_list	*temp2;

	temp2 = *list1;
	temp = malloc(sizeof(t_list));
	if (*list1 != NULL)
	{
		while (temp2->next != NULL)
			temp2 = temp2->next;
		temp->data = temp2->data;
		temp->next = *list1;
		*list1 = delete_last_node(temp);
	}
}

void	ft_rrb_bonus(t_list **list2)
{
	t_list	*temp;
	t_list	*temp2;

	temp2 = *list2;
	temp = malloc(sizeof(t_list));
	if (*list2 != NULL)
	{
		while (temp2->next != NULL)
			temp2 = temp2->next;
		temp->data = temp2->data;
		temp->next = *list2;
		*list2 = delete_last_node(temp);
	}
}
