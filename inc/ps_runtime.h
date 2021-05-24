/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_runtime.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clsaad <clsaad@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 10:41:30 by clsaad            #+#    #+#             */
/*   Updated: 2021/05/19 10:41:31 by clsaad           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_RUNTIME_H
# define PS_RUNTIME_H

# include <ft_arraylist.h>

# include "lifo_stack.h"
# include "ops.h"

typedef struct s_runtime
{
	t_arraylist		ops;
	t_lifo_stack	stack_a;
	t_lifo_stack	stack_b;
}			t_runtime;

enum e_rtinit_ret
{
	RTINIT_OK,
	RTINIT_NOARG,
	RTINIT_WRONGARGS,
	RTINIT_ALLOCERROR
};

t_runtime			*rt_ptr(void);
enum e_rtinit_ret	rt_init_args(int argc, char *argv[]);
void				rt_exit(int code)__attribute__((noreturn));

#endif // PS_RUNTIME_H
