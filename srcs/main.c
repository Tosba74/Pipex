/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 18:37:34 by bmangin           #+#    #+#             */
/*   Updated: 2021/07/07 17:29:54 by bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex(char **av)
{
	int	fd1;	
	int	fd2;	
	
	fd1 = open (av[1], O_DIRECTORY);
	if (fd1 > 0)
	{
		close(fd1);
		return (error("T'es un correcteur relou ! \n"));
	}
	close(fd1);
	fd1 = open(av[1], O_RDONLY);
	fd2 = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (fd1 == -1 || fd2 == -1)
	{
		close(fd1);
		close(fd2);
		return (error("file 1 or file2 invalid\n"));
	}
	else
		return (error("command : ./pipex file1 \"cmd1\" \"cmd2\" file2\n"));
	return (0);	
}

int	main(int ac, char **av)
{
	if (ac == 5)
	{
		pipex(av);	
	}
	else
	{
		printf("Pipex syntax: file1 cmd1 cmd2 file2\n");
		printf("Like command '|':\n");	
		printf("< file1 cmd1| cmd2 > file2\n");	
	}
	return (0);
}
