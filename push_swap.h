/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jknotts <jknotts@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 10:19:37 by jknotts           #+#    #+#             */
/*   Updated: 2022/01/10 16:55:35 by jknotts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_list
{
	struct s_list	*n;
	int				nbr;
	int				index;
}	t_list;
int			ft_atoi(const char *str);
void		*ft_calloc(size_t count, size_t size);
void		*ft_memset(void *b, int c, size_t len);
char		*ft_strdup(char *str);
char		*ft_substr(char const *s, int start, size_t len);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
int			ft_strlen(const char *s);
char		**ft_split(char const *s, char c);
void		ft_push_to_front(t_list **begin_list, int nbr);
t_list		*ft_create_el(int nbr);
void		ft_print_list(t_list *head);
void		sa(t_list **stack_a, int print_action);
void		sb(t_list **stack_b, int print_action);
void		ss(t_list **stack_a, t_list **stack_b);
void		pb(t_list **stack_a, t_list **stack_b, int print_action);
void		ra(t_list **stack_a, int print_action);
void		pa(t_list **stack_a, t_list **stack_b, int print_action);
void		rb(t_list **stack_b, int print_action);
void		rr(t_list **stack_a, t_list **stack_b);
void		rra(t_list **stack_a, int print_action);
void		rrb(t_list **stack_b, int print_action);
void		rrr(t_list **stack_a, t_list **stack_b);
void		ft_free_mem(t_list *stack);
int			ft_ptrcap(char **str);
void		ft_error(void);
void		ft_parse_string(char **str, t_list **stack_a);
int			ft_size(t_list **stack);
void		ft_repeat_values_valid(t_list *stack_a);
void		ft_push_values_on_stack(int argc, char **argv);
int			ft_sort_valid(t_list *stack_a);
int			ft_max(t_list **stack);
int			*ft_list_to_arr(t_list *stack_a, int arr_length);
int			*ft_bubble_sort_array(t_list *stack_a);
void		ft_sort(t_list *stack_a);
void		ft_sort_tree_el(t_list **stack_a);
void		ft_sort_four_el(t_list **stack_a);
void		ft_sort_five_el(t_list **stack_a);
void		ft_stack_index(int *arr, t_list *stack_a);
void		ft_move_to_stack_b(t_list **stack_a, int range);
int			ft_arr_nbr(int *arr, int i);
int			ft_strcmp(char *s1, char *s2);
int			ft_side(t_list **stack_b, int max, int stack_b_size);
void		ft_move_to_stack_a(t_list **st_b);
void		ft_sort_type(t_list *stack_a);
void		ft_sort_five_el_2(t_list **a, t_list *stack_b);
void		ft_move_case_3(t_list **stack_a, t_list *stack_b);
void		ft_move_case_2(t_list **stack_a, t_list *stack_b);
void		ft_sort_a(t_list **stack_a);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strchr(const char *s, int c);
char		*get_next_line(int fd);
char		*ft_new_save(char *save);
char		*ft_new_line(char *save);
char		*ft_read_and_save(int fd, char *save);
int			ft_strcmp(char *s1, char *s2);

#endif
