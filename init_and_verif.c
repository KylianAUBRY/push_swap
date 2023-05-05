/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_verif.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaubry <kyaubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 07:52:45 by kyaubry           #+#    #+#             */
/*   Updated: 2023/05/05 12:09:43 by kyaubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_add_node_end(int i)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	new->data = i;
	new->next = NULL;
	return (new);
}

int	verif_char(char *argv)
{
	int	i;

	i = 0;
	if (argv[i] == '-')
		i++;
	while (argv[i] && argv[i] != ' ')
	{
		if ((argv[i] > '9' || argv[i] < '0') && argv[i] != ' '
			&& argv[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

int	verif_number_sort(t_list *list)
{
	t_list	*temp;
	void	*test;

	temp = list;
	if (temp->next == NULL)
	{
		free(list);
		return (0);
	}
	while (temp->next->next != NULL && temp->data < temp->next->data)
	{
		temp = temp->next;
	}
	if (temp->data < temp->next->data && temp->next->next == NULL)
	{
		while (list->next != NULL)
		{
			test = list->next;
			free(list);
			list = test;
		}
		free(list);
		return (0);
	}
	return (1);
}

int	verif_double(t_list *list)
{
	t_list	*temp;
	t_list	*temp2;

	temp = list;
	temp2 = list;
	while (temp->next != NULL)
	{
		while (temp2->next != NULL)
		{
			temp2 = temp2->next;
			if (temp->data == temp2->data)
				return (erreur_double(list));
		}
		temp = temp->next;
		temp2 = temp;
	}
	return (verif_number_sort(list));
}

int	charg_list(t_list **list, int argc, char **argv)
{
	int		i;
	t_list	*temp;

	i = 1;
	temp = *list;
	temp->next = NULL;
	while (i < argc)
	{
		if (ft_split(argv[i], list) == 0)
			return (0);
		i++;
	}
	temp = *list;
	temp = delete_first_node(temp);
	*list = temp;
	return (verif_double(*list));
}
