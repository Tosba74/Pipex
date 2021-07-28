r /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 04:40:00 by bmangin           #+#    #+#             */
/*   Updated: 2021/07/25 22:03:56 by bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	waiting_pid(t_pipex *p)
{
	int	i;
	int	ret;
	int	wstatus;

	i = -1;
	while (++i < p->index)
	{
		waitpid(p->pids[i], &wstatus, 0);
		if (WIFEXITED(wstatus))
			ret = (unsigned char)WEXITSTATUS(wstatus);
	}
	return (ret);
}

static void	child_process(t_pipex *p, char *av, const int prev)
{
	if (p->in)
	{
		dup2(prev, STDIN_FILENO);
		close (prev);
	}
	if (p->out)
	{
		dup2(p->pipefd[1], STDIN_FILENO);
		close (p->pipefd[1]);
	}
	execve(&prev, ft_split(av, ' '), p->env);
	// printf("Command => %s\n", p->cmd);
	// execve(p->cmd, ft_split(av, ' '), p->env);
	// execve(p->cmd, &av, p->env);
	ft_err("EXECVE ERROR:", 5);
}

static void	exec_jobs(t_pipex *p, char *av)
{
	const int	prev_in = p->pipefd[0];
	pid_t		pid;

	if (p->out)
		if (pipe(p->pipefd) < 0)
			ft_err("ExecJobs:", 3);
	pid = fork();
	if (pid < 0)
		ft_err("ExecJobs:", 4);
	else if (pid == 0)
		child_process(p, av, prev_in);
	else
	{
		p->pids[p->index++] = pid;
		if (p->in)
			close(prev_in);
		if (p->out)
			close(p->pipefd[1]);
		// ft_err("FINISH", 9);
	}
}

int	exec(int ac, char **av, char **env, t_pipex *p)
{
	int		i;

	i = 1;
	while (i++ < ac - 2)
	{
		init_bool(i, ac, p);
		init_cmd(p->cmd, av[i], env);
		p->env = env;
		exec_jobs(p, av[i]);
	}
	return (waiting_pid(p));
}
