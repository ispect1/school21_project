/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljonnel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 02:26:17 by ljonnel-          #+#    #+#             */
/*   Updated: 2019/05/19 02:26:18 by ljonnel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"

typedef struct	s_stack
{
	int			alen;
	int			blen;
	int			*a;
	int			*b;
	int			pivot;
	int			print;
	int			time;
}				t_stack;

void			sort_less_10_dop(t_stack *stack, int *a);
void			sort_less_10(t_stack *stack);
int				pos_min(int *a, int len);
void			sort_only_3(t_stack *stack);
void			ps_p(t_stack *stack, char c, int n);
void			ps_s(int *a, int len, char c, t_stack *stack);
int				ps_r(int *a, int len, char c, t_stack *stack);
void			ps_rr(int *a, int len, char c, t_stack *stack);
int				check_sort(int *a, int len, int true_len, char c);
int				*reader(int ac, char **av);
void			sort_3_or_2_param1(t_stack *stack, int len, int n);
void			sort_3_or_2_param2(t_stack *stack, int *elem);
void			quick_sort(int *a, int n);
int				partition(int *a, int n);
int				check(int ac, char **av);
int				determ_pivot(int *a, int n, int truelen);
int				check_copie(int *a, int len);
void			sort_stackb2(t_stack *stack, int i, int tmp, int n);
void			sort_stackb(t_stack *stack, int n);
void			sort_stacka2(t_stack *stack, int i, int tmp, int n);
void			sort_stacka(t_stack *stack, int n);
#endif
