/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lifo_stack.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clsaad <clsaad@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 14:05:10 by clsaad            #+#    #+#             */
/*   Updated: 2021/05/17 14:05:12 by clsaad           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIFO_STACK_H
# define LIFO_STACK_H

# include <stddef.h>
# include <stdint.h>

typedef struct s_lifo_stack
{
	int			*data;
	size_t		stack_size;
	size_t		elem_count;
}				t_lifo_stack;

int		lifo_ctor(t_lifo_stack *this, size_t size);
void	lifo_dtor(t_lifo_stack *this);
int		lifo_at(t_lifo_stack *this, size_t index);
void	lifo_pushval(t_lifo_stack *this, int value);
int		lifo_head(t_lifo_stack *this);

void	lifo_swap(t_lifo_stack *this);
void	lifo_push(t_lifo_stack *this, t_lifo_stack *src);
void	lifo_rotate(t_lifo_stack *this);
void	lifo_reverse_rotate(t_lifo_stack *this);

#endif // LIFO_STACK_H
