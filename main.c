/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaubry <kyaubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 00:25:08 by kyaubry           #+#    #+#             */
/*   Updated: 2023/05/05 12:09:50 by kyaubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_switch_list(t_list **list1, t_list **list2)
{
	t_list	*temp;
	t_list	*temp2;

	free_list1(*list1);
	temp = malloc(sizeof(t_list));
	temp->next = NULL;
	*list1 = temp;
	temp2 = *list2;
	temp = *list1;
	while (temp2 != NULL)
	{
		temp->next = ft_add_node_end(temp2->data);
		temp = temp->next;
		temp2 = temp2->next;
	}
	*list1 = delete_first_node(*list1);
	free_list1(*list2);
}

void	ft_chang_val(t_list **list1, t_list **list2)
{
	t_list	*temp;
	t_list	*temp2;
	int		i;

	temp = *list1;
	while (temp != NULL)
	{
		i = 0;
		temp2 = *list1;
		while (i >= 0)
		{
			if (temp->data >= temp2->data)
				i++;
			if (temp2->next == NULL)
				break ;
			temp2 = temp2->next;
		}
		temp = temp->next;
		temp2 = *list2;
		while (temp2->next != NULL)
			temp2 = temp2->next;
		temp2->next = ft_add_node_end(i);
	}
	*list2 = delete_first_node(*list2);
	ft_switch_list(list1, list2);
}

void	sort_bits(t_list **list1, t_list **list2, int i, int count_list)
{
	t_list	*temp;
	int		j;

	j = 0;
	while (j < count_list)
	{
		temp = *list1;
		if (get_bit(temp->data, i) == 1)
			ft_ra(list1);
		else
			ft_pb(list1, list2);
		j++;
	}
}

void	sort_big_stack(t_list **list1, t_list **list2, int count_list)
{
	t_list	*temp;
	int		max_num;
	int		max_bits;
	int		i;

	max_num = count_list;
	max_bits = 0;
	i = 0;
	while ((max_num >> max_bits) != 0)
		max_bits++;
	while (i < max_bits)
	{
		sort_bits(list1, list2, i, count_list);
		temp = *list2;
		while (temp != NULL)
		{
			ft_pa(list1, list2);
			temp = *list2;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		count_list;
	t_list	*list1;
	t_list	*list2;

	if (argc <= 1)
		return (0);
	list1 = malloc(sizeof(t_list));
	if (charg_list(&list1, argc, argv) == 0)
		return (0);
	list2 = NULL;
	count_list = compt_list(list1);
	if (count_list <= 3)
		ft_mall_small(&list1, count_list);
	else if (count_list == 5 || count_list == 4)
		ft_five(&list1, &list2, count_list);
	else
	{
		list2 = malloc(sizeof(t_list));
		list2->next = NULL;
		ft_chang_val(&list1, &list2);
		list2 = NULL;
		sort_big_stack(&list1, &list2, count_list);
	}
	free_list(list1, list2);
}

/*void	ft_print(t_list *list, t_list *list2)
{
	t_list	*temp;

	temp = list;
	while (temp != NULL)
	{
		printf("%d\n", temp->data);
		temp = temp->next;
	}
	printf("list 2\n");
	temp = list2;
	while (temp != NULL)
	{
		printf("%d\n", temp->data);
		temp = temp->next;
	}
}*/