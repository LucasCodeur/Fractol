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

int	compute_double(char *str, double *int_part, double *deci_part, t_bool *dot_encount, int *i)
{
    int	nb_of_decimal;

    nb_of_decimal = 0;
    if (*dot_encount == FALSE)
        *int_part = *int_part * 10 + (str[*i] - 48);
    else
    {
        *deci_part = *deci_part * 10 + (str[*i] - 48);
        nb_of_decimal++;
    }
    (*i)++;
    return (nb_of_decimal);
}

long double ft_atod(char *str)
{
    double  int_part;
    double  dec_part;
    int	    nb_of_dec;
    t_bool  dot_encounter;
    int	    i;

    dot_encounter = FALSE;
    int_part = 0.0;
    dec_part = 0.0;
    nb_of_dec = 0.0;
    i = 0;
    if (ft_is_plus_or_minus(str[i]) == TRUE)
    {
	if str[]
    }
    while (str[i] != '\0')
    {
	if (str[i] == '.')
	{
	    dot_encounter = TRUE;
	    i++;
	}
	nb_of_dec = compute_double(str, &int_part, &dec_part, &dot_encounter, &i);
    }
    return (integer_part + fractional_part / pow(10, nb_of_dec)); 
}
