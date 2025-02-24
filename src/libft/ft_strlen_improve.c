/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_improve.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:43:00 by lud-adam          #+#    #+#             */
/*   Updated: 2025/02/24 17:57:41 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen_improve(const char *str, char c)
{
	size_t	i;

	i = 0;
	while (str && str[i] != c)
		i++;
	return (i);
}
