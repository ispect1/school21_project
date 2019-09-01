/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljonnel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 02:29:15 by ljonnel-          #+#    #+#             */
/*   Updated: 2019/05/19 02:29:17 by ljonnel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "unistd.h"
#include <time.h>

void	print_stacks(t_stack *stack)
{
	int len;
	int lena;
	int lenb;

	write(1, "\e[1;1H\e[2J", 10);
	write(1, "Stack A    |    Stack B\n", 24);
	lena = stack->alen - 1;
	lenb = stack->blen - 1;
	len = (stack->alen >= stack->blen) ? stack->alen : stack->blen;
	while (--len >= 0)
	{
		if (lena >= 0)
			ft_putnbr(stack->a[lena]);
		(lena >= 0) ? write(1, "          ", 11 - numb_dig(stack->a[lena--]))
		: write(1, "           ", 11);
		write(1, "|", 1);
		if (lenb >= 0)
		{
			write(1, "    ", 4);
			ft_putnbr(stack->b[lenb--]);
		}
		write(1, "\n", 1);
	}
	usleep(stack->time);
}

void	ps_p(t_stack *stack, char c, int n)
{
	while (n-- > 0)
		if (c == 'a' && stack->blen > 0)
		{
			stack->blen--;
			stack->a[stack->alen++] = stack->b[stack->blen];
			stack->b[stack->blen] = 0;
			(stack->print == 1) ? write(1, "pa\n", 3) : 0;
		}
		else if (c == 'b' && stack->alen > 0)
		{
			stack->alen--;
			stack->b[stack->blen++] = stack->a[stack->alen];
			stack->a[stack->alen] = 0;
			(stack->print == 1) ? write(1, "pb\n", 3) : 0;
		}
	if (stack->print == 2)
		print_stacks(stack);
}

void	ps_s(int *a, int len, char c, t_stack *stack)
{
	int tmp;

	tmp = a[len - 1];
	a[len - 1] = a[len - 2];
	a[len - 2] = tmp;
	if (c == 'a' && stack->print == 1)
		write(1, "sa\n", 3);
	else if (stack->print == 1)
		write(1, "sb\n", 3);
	if (stack->print == 2)
		print_stacks(stack);
}

int		ps_r(int *a, int len, char c, t_stack *stack)
{
	int tmp;

	tmp = a[len - 1];
	while (--len > 0)
		a[len] = a[len - 1];
	a[0] = tmp;
	if (c == 'a' && stack->print == 1)
		write(1, "ra\n", 3);
	else if (stack->print == 1)
		write(1, "rb\n", 3);
	if (stack->print == 2)
		print_stacks(stack);
	return (1);
}

void	ps_rr(int *a, int len, char c, t_stack *stack)
{
	int tmp;
	int i;
	int tlen;

	tlen = len;
	i = 0;
	tmp = a[0];
	while (--len > 0)
	{
		a[i] = a[i + 1];
		i++;
	}
	a[tlen - 1] = tmp;
	if (c == 'a' && stack->print == 1)
		write(1, "rra\n", 4);
	else if (stack->print == 1)
		write(1, "rrb\n", 4);
	if (stack->print == 2)
		print_stacks(stack);
}
