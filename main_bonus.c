/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaubry <kyaubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 09:41:27 by kyaubry           #+#    #+#             */
/*   Updated: 2023/05/04 17:27:58 by kyaubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rrr_bonus(t_list **list1, t_list **list2)
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
}

int	compart(char *c, char *src)
{
	int	i;

	if (!c || !src)
		return (0);
	i = 0;
	while (c[i] && src[i])
	{
		if (c[i] != src[i])
			return (0);
		i++;
	}
	if (c[i] != src[i])
		return (0);
	return (1);
}

int	ft_erreur(t_list **list1, t_list **list2, char *c)
{
	t_list	*temp;

	if (!list1)
		return (ft_putstr("KO\n"));
	temp = *list1;
	if (c != NULL)
		return (ft_putstr_zero("Error\n"));
	while (temp->next != NULL)
	{
		if (temp->data > temp->next->data)
			return (ft_putstr("KO\n"));
		temp = temp->next;
	}
	temp = *list2;
	if (temp != NULL)
		return (ft_putstr("KO\n"));
	return (ft_putstr("OK\n"));
}

int	call_function(t_list **list1, t_list **list2, char *c)
{
	if (compart(c, "sa\n") == 1)
		ft_sa_bonus(*list1);
	else if (compart(c, "sb\n") == 1)
		ft_sb_bonus(*list2);
	else if (compart(c, "ss\n") == 1)
		ft_ss_bonus(*list1, *list2);
	else if (compart(c, "pa\n") == 1)
		ft_pa_bonus(list1, list2);
	else if (compart(c, "pb\n") == 1)
		ft_pb_bonus(list1, list2);
	else if (compart(c, "ra\n") == 1)
		ft_ra_bonus(list1);
	else if (compart(c, "rb\n") == 1)
		ft_rb_bonus(list2);
	else if (compart(c, "rr\n") == 1)
		ft_rr_bonus(list1, list1);
	else if (compart(c, "rra\n") == 1)
		ft_rra_bonus(list1);
	else if (compart(c, "rrb\n") == 1)
		ft_rrb_bonus(list2);
	else if (compart(c, "rrr\n") == 1)
		ft_rrr_bonus(list1, list2);
	else
		return (ft_erreur(list1, list2, c));
	return (-1);
}

int	main(int argc, char **argv)
{
	t_list	*list1;
	t_list	*list2;
	char	*c;
	int		i;

	if (argc <= 1)
		return (0);
	list1 = malloc(sizeof(t_list));
	if (charg_list(&list1, argc, argv) == 0)
		return (0);
	i = 0;
	list2 = NULL;
	while (i != -1)
	{
		c = get_next_line(0);
		if (call_function(&list1, &list2, c) != -1)
		{
			free(c);
			break ;
		}
		free(c);
	}
	free_list(list1, list2);
}
