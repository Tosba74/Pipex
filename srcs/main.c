/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 04:40:14 by bmangin           #+#    #+#             */
/*   Updated: 2021/07/24 12:04:18bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	init_fd(t_fd *fd, char *file1, char *file2)
{
	fd = wrmalloc(sizeof(t_fd));
	fd->fd_in = open (file1, O_DIRECTORY);
	if (fd->fd_in > 0)
	{
		close(fd->fd_in);
		ft_err("File opening:\n", 0);
	}
	close(fd->fd_in);
	fd->fd_in = open(file1, O_RDONLY);
	fd->fd_out = open(file2, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (fd->fd_in == -1 || fd->fd_out == -1)
	{
		close(fd->fd_in);
		close(fd->fd_out);
		ft_err("File opening:\n", 1);
	}
}

int	pipex(int ac, char **av, char **env)
{
	t_pipex	p;

	p = (t_pipex){};
	init_fd(&p.fd, av[1], av[ac - 1]);
	return (exec(ac, av, env, &p));
}

int	main(int ac, char **av, char **env)
{
	if (ac > 4)
		return (pipex(ac, av, env));
	else
		ft_err("Command:\n", 2);
	return (0);
}
