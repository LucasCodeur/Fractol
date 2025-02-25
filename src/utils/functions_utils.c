/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:31:29 by lud-adam          #+#    #+#             */
/*   Updated: 2025/02/24 17:59:03 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

void	compute_double(char *str, t_decimal_nb *nb, t_bool *dot_encount, int *i)
{
	if (*dot_encount == FALSE)
		nb->int_part = nb->int_part * 10 + (str[*i] - 48);
	else
	{
		nb->dec_part = nb->dec_part * 10 + (str[*i] - 48);
		nb->of_decs++;
	}
	(*i)++;
}

long double	ft_atod(char *str)
{
	t_decimal_nb	nb;

	nb.dot_encounter = FALSE;
	nb.int_part = 0.0;
	nb.dec_part = 0.0;
	nb.of_decs = 0;
	nb.sign = 1.0;
	nb.i = 0;
	if (ft_is_plus_or_minus(str[nb.i]) == TRUE)
	{
		if (str[nb.i] == '-')
			nb.sign = -1.0;
		nb.i++;
	}
	while (str[nb.i] != '\0')
	{
		if (str[nb.i] == '.')
		{
			nb.dot_encounter = TRUE;
			nb.i++;
		}
		compute_double(str, &nb, &nb.dot_encounter, &nb.i);
	}
	nb.result = (nb.int_part + nb.dec_part / pow(10, nb.of_decs)) * nb.sign;
	return (nb.result);
}
