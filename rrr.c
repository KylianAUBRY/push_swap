/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaubry <kyaubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 11:42:50 by kyaubry           #+#    #+#             */
/*   Updated: 2023/05/01 12:24:37 by kyaubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*delete_last_node(t_list *head)
{
	t_list	*temp;

	temp = head;
	if (head == NULL)
		return (head);
	while (temp->next->next != NULL)
		temp = temp->next;
	free(temp->next);
	temp->next = NULL;
	return (head);
}

void	ft_rra(t_list **list1)
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
	ft_putstr("rra\n");
}

void	ft_rrb(t_list **list2)
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
	ft_putstr("rrb\n");
}

void	ft_rrr(t_list **list1, t_list **list2)
{
	t_list	*temp;
	t_list	*temp2;
	t_list	*temp3;

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
	temp2 = *list2;
	temp3 = malloc(sizeof(t_list));
	if (*list2 != NULL)
	{
		while (temp2->next != NULL)
			temp2 = temp2->next;
		temp3->data = temp2->data;
		temp3->next = *list2;
		*list2 = delete_last_node(temp3);
	}
	ft_putstr("rrr\n");
}
