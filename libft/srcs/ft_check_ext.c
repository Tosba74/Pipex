/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_ext.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 17:40:20 by bmangin           #+#    #+#             */
/*   Updated: 2021/07/18 19:16:47 by bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check_ext(char *s, char *ext)
{
	char	*cmp;

	if (!ft_strrchr(s, 46))
		return (FAILURE);
	cmp = ft_strdup(ft_strrchr(s, 46));
	if (ft_strncmp(cmp, ext, 4))
		return (FAILURE);
	wrfree(cmp);
	return (SUCCESS);
}
