/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okruhlia <okruhlia@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 19:52:50 by okruhlia          #+#    #+#             */
/*   Updated: 2025/12/08 00:22:47 by okruhlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# include "ft_printf.h"
# include "libft.h"
# include <stdbool.h>

typedef struct s_stack
{
	int				fig;
	int				index;
	int				push_cost;
	bool			above_median;
	bool			cheapest;
	struct s_stack	*target_node;
	struct s_stack	*next_node;
	struct s_stack	*prev_node;
}	t_stack;

int				main(int argc, char **argv);

//***** Error Handler *****
void			invalid_argv(void);
void			invalid_stack(t_stack **head);

//***** Validation *****
int				argv_validation(int argc, char **argv);
int				validate_single_argv(char *arg);
int				validate_multiple_argv(size_t args_quant, char **argv);
int				validate_fig_str(char *str);
void			free_new_argv(char **argv);
int				repetition_validation(t_stack *node, int fig);
int				sorted_validation(t_stack *node);

//***** Stack Creation *****
void			stack_a_creating(t_stack **stack_a, int argc, char **argv);
void			proces_single_argv(t_stack **stack_a, char *arg);
void			proces_multiple_argv(t_stack **stack_a, size_t args_quant,
					char **argv);

//**** Node CRUD *****
void			append_node(t_stack **stack_a, int fig);
t_stack			*find_last_node(t_stack *node);
size_t			stack_length(t_stack *node);
void			free_stack(t_stack **head);
t_stack			*find_highest_node(t_stack *stack_a);
void			init_stack(t_stack *stack_a, t_stack *stack_b);
void			set_current_position(t_stack *stack);
static void		set_target_node(t_stack *stack_a, t_stack *stack_b);
t_stack			*find_smallest_node(t_stack *stack);
void			set_price(t_stack *stack_a, t_stack *stack_b);
void			set_cheapest(t_stack *stack_b);
t_stack			*return_cheapest(t_stack *stack);

//***** Sorting Algorithm *****
void			sort_small(t_stack **stack_a);
void			sort_five(t_stack **stack_a, t_stack **stack_b);
void			sort_big(t_stack **stack_a, t_stack **stack_b);

//***** Commands *****
void			swap(t_stack **head);
void			sa(t_stack **a);
void			sb(t_stack **b);
void			ss(t_stack **a, t_stack **b);
void			push(t_stack **dest, t_stack **src);
void			pa(t_stack **a, t_stack **b);
void			pb(t_stack **b, t_stack **a);
void			rotate(t_stack **head);
void			ra(t_stack **a);
void			rb(t_stack **b);
void			rr(t_stack **a, t_stack **b);
void			reverse_rotate(t_stack **head);
void			rra(t_stack **a);
void			rrb(t_stack **b);
void			rrr(t_stack **a, t_stack **b);
void			move_nodes(t_stack **stack_a, t_stack **stack_b);
void			finish_rotation(t_stack **stack, t_stack *top_node,
					char stack_name);
static void		rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node);
static void		reverse_rotate_both(t_stack **a, t_stack **b,
					t_stack *cheapest_node);

#endif
