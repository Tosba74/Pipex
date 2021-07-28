/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 18:37:28 by bmangin           #+#    #+#             */
/*   Updated: 2021/07/25 02:07:15 by bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# define MAX_PROCCESS 1392
// ulimit -u

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdbool.h>
# include <sys/types.h>
# include <sys/wait.h>

# include "../libft/includes/libft.h"

typedef struct s_fd
{
	int			fd1;
	int			fd2;
}	t_fd;

typedef struct s_pipex
{
	int		index;
	int		pipefd[2];
	char	*cmd;
	char	**av;
	char	**env;
	bool	in;
	bool	out;
	t_fd	fd;
	pid_t	pids[MAX_PROCCESS];
}	t_pipex;

// tool.c
void	ft_err(char *s, int err);
void	init_bool(int index, int ac, t_pipex *p);
void	init_cmd(char *cmd, char *av, char **env);

// pipex.c
int		exec(int ac, char **av, char **env, t_pipex *p);

#endif
