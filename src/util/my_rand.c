/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_rand.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 22:30:43 by yumamur           #+#    #+#             */
/*   Updated: 2024/05/28 08:28:26 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

static uint64_t	*seed(void)
{
	static uint64_t	seed;

	return (&seed);
}

static void __attribute__((constructor))	seed_constructor(void)
{
	*seed() = 7564231;
}

void	set_seed(uint64_t sd)
{
	*seed() = sd;
}

double	mock_rand(void)
{
	*seed() = *seed() * 6364136223846793005L + 1;
	return ((double)(*seed() >> 33) / (double)(1L << 31));
}

double	mock_rand_range(double min, double max)
{
	return (mock_rand() * (max - min) + min);
}
