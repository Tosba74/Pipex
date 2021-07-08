/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 18:37:28 by bmangin           #+#    #+#             */
/*   Updated: 2021/07/07 17:31:02 by bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# ifndef PIPE_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "libft/libft.h"

// pipex.c
void	pipex(char **av);

#endif
