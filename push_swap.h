/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaubry <kyaubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 00:25:30 by kyaubry           #+#    #+#             */
/*   Updated: 2023/05/04 17:24:10 by kyaubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

typedef struct s_list
{
	int				data;
	struct s_list	*next;
}					t_list;

int					verif_char(char *argv);
int					ft_split(char *s, t_list **list);
long long int		ft_atoi_modif(const char *nptr);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstadd_front(t_list **lst, t_list *new);
t_list				*ft_lstlast(t_list *lst);
int					ft_putstr_zero(char *dest);
int					ft_putstr(char *dest);
void				free_list(t_list *list1, t_list *list2);
void				free_list1(t_list *list1);
int					erreur_int(t_list *list);
int					erreur_double(t_list *list);
int					charg_list(t_list **list, int argc, char **argv);
t_list				*delete_first_node(t_list *head);
t_list				*delete_last_node(t_list *head);
void				ft_sa(t_list *list);
void				ft_sb(t_list *list);
void				ft_ss(t_list *list, t_list *list2);
void				ft_pa(t_list **list1, t_list **list2);
void				ft_pb(t_list **list1, t_list **list2);
void				ft_ra(t_list **list1);
void				ft_rb(t_list **list2);
void				ft_rr(t_list **list1, t_list **list2);
void				ft_rra(t_list **list1);
void				ft_rrb(t_list **list2);
void				ft_rrr(t_list **list1, t_list **list2);
void				ft_five(t_list **list1, t_list **list2, int count_list);
void				ft_four(t_list **list1, t_list **list2);
int					verif_first(t_list *list1);
void				ft_mall_small(t_list **list, int count_list);
void				ft_three(t_list **list);
t_list				*ft_add_node_end(int i);
int					get_bit(int num, int bit);
int					compt_list(t_list *list);
char				*get_next_line(int fd);
int					ft_chr(char *s);
char				*ft_join(char *s1, char *s2);
void				ft_buf_cut(char *dest);
int					ft_len(char *s, int j);
void				ft_sa_bonus(t_list *list);
void				ft_sb_bonus(t_list *list);
void				ft_ss_bonus(t_list *list, t_list *list2);
void				ft_pa_bonus(t_list **list1, t_list **list2);
void				ft_pb_bonus(t_list **list1, t_list **list2);
void				ft_ra_bonus(t_list **list1);
void				ft_rb_bonus(t_list **list2);
void				ft_rr_bonus(t_list **list1, t_list **list2);
void				ft_rra_bonus(t_list **list1);
void				ft_rrb_bonus(t_list **list2);
void				ft_rrr_bonus(t_list **list1, t_list **list2);
void				ft_print(t_list *list, t_list *list2);

#endif
