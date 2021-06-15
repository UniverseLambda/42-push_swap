/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clsaad <clsaad@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 11:05:35 by clsaad            #+#    #+#             */
/*   Updated: 2021/05/19 11:05:36 by clsaad           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPS_H
# define OPS_H

# include <lifo_stack.h>

enum e_ops
{
	NOOP,
	SWAP_A,
	SWAP_B,
	SWAP_AB,
	PUSH_A,
	PUSH_B,
	ROT_A,
	ROT_B,
	ROT_AB,
	REV_ROT_A,
	REV_ROT_B,
	REV_ROT_AB,
};

void	optimize_ops(void);

int		swap_a(void);
int		swap_b(void);
int		swap_ab(void);
int		push_a(void);
int		push_b(void);
int		rot_a(void);
int		rot_b(void);
int		rot_ab(void);
int		rrot_a(void);
int		rrot_b(void);
int		rrot_ab(void);

int		swap_x(t_lifo_stack *stack);
int		push_x(t_lifo_stack *stack);
int		rot_x(t_lifo_stack *stack);
int		rrot_x(t_lifo_stack *stack);

#endif // OPS_H
