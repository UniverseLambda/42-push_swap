/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ovm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clsaad <clsaad@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 10:11:41 by clsaad            #+#    #+#             */
/*   Updated: 2021/06/29 10:11:42 by clsaad           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef OVM_H
# define OVM_H

# include <stddef.h>
# include <ft_stdbool.h>

# include <ps_runtime.h>

typedef struct s_ovm_lifo
{
	size_t	elem_count;
}				t_ovm_lifo;

typedef struct s_ovm
{
	size_t		rip;
	t_arraylist	*ops;
	t_ovm_lifo	sa;
	t_ovm_lifo	sb;
}				t_ovm;

typedef struct s_ovm_frame
{
	size_t		start;
	size_t		end;
	size_t		size;
}				t_ovm_frame;

t_ovm	init_ovm();
t_ovm	ovm_until_nop(t_ovm ovm, enum e_ops op);
t_ovm	ovm_until_op(t_ovm ovm, enum e_ops op);
t_ovm	ovm_until_index(t_ovm ovm, size_t opidx);
void	ovm_next(t_ovm *ovm);

t_bool	ovm_optimize();
void	ovm_merge();

#endif // OVM_H
