/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaubry <kyaubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 11:39:16 by kyaubry           #+#    #+#             */
/*   Updated: 2023/05/02 02:20:41 by kyaubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*delete_first_node(t_list *head)
{
	t_list	*temp;

	if (head == NULL)
		return (head);
	temp = head;
	if (temp->next != NULL)
		head = temp->next;
	else
		head = NULL;
	free(temp);
	return (head);
}

void	ft_ra(t_list **list1)
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
	ft_putstr("ra\n");
}

void	ft_rb(t_list **list2)
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
	ft_putstr("rb\n");
}

void	ft_rr(t_list **list1, t_list **list2)
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
	ft_putstr("rr\n");
}
