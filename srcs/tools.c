/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 04:13:31 by bmangin           #+#    #+#             */
/*   Updated: 2021/07/28 14:21:42 by bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*msg_err(int i)
{
	static char	*tab[10];

	tab[0] = "Dude! Use \"file\" pls!\n";
	tab[1] = "invalid file\n";
	tab[2] = "./pipex file1 \"cmd1\" \"cmd2\" file2\n";
	tab[3] = "Pipe error";
	tab[4] = "Fork error";
	tab[5] = "ZOMBIE Child\n";
	tab[6] = "Dude! Use real command";
	tab[7] = "";
	tab[8] = "";
	tab[9] = "\n";
	return (tab[i]);
}

void	ft_err(char *s, int err)
{
	char	*str_err;

	str_err = msg_err(err);
	ft_putstr("Error :\n");
	printf("%s: %s\n", s, str_err);
	wrdestroy();
	exit(1);
}

void	init_bool(int index, int ac, t_pipex *p)
{
	p->in = true;
	p->out = true;
	if (index == 2)
		p->in = false;
	else if (index == ac - 1)
		p->out = false;
}

void	init_cmd(char *cmd, char *av, char **env)
{
	if (cmd)
		wrfree(cmd);
	cmd = select_env_path(av, env);
	printf("CMD ==> %s\n", cmd);
	if (!cmd)
		ft_err("COMMAND:", 6);
	printf("COMMAND => %s\n", cmd);
}
