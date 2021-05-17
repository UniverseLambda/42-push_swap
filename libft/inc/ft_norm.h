/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_norm.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clsaad <clsaad@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 12:11:52 by clsaad            #+#    #+#             */
/*   Updated: 2021/03/17 12:11:53 by clsaad           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NORM_H
# define FT_NORM_H

# include <stdint.h>
# include <stddef.h>

// Ternary

char				ft_tern_c(int cond, char a, char b);
int					ft_tern_i(int cond, int a, int b);
uint64_t			ft_tern_u64(int cond, uint64_t a, uint64_t b);
double				ft_tern_d(int cond, double a, double b);

// Min

size_t				ft_min_zu(size_t a, size_t b);
double				ft_min_d(double a, double b);
unsigned long long	ft_min_ull(unsigned long long a, unsigned long long b);

// Min non zero

unsigned long long	ft_minnz_ull(unsigned long long a, unsigned long long b);

// Max

unsigned long long	ft_max_ull(unsigned long long a, unsigned long long b);
size_t				ft_max_zu(size_t a, size_t b);
double				ft_max_d(double a, double b);

/*
** WARNING !
** This method should take a ```X **``` (double-pointer to X)
*/

void				*set_ptr(void *target, void *value);
int					set_i(int *target, int value);
int					set_uc(unsigned char *target, unsigned char value);

#endif // FT_NORM_H
