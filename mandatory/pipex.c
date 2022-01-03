/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eanastas <eanastas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 18:06:41 by eanastas          #+#    #+#             */
/*   Updated: 2021/12/31 18:08:03 by eanastas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
	pid -> process id
	pipe(int *fd) creates pipe, where fd[0] is read end and fd[1] is write end
	pid = fork() means -> creates identical process as current -> child
	dup2(fd[0], STDIN_FILENO); -> считать инфу из данного файла в трубу
*/

void	child_process(t_pipex *pipex)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		error();
	pid = fork();
	if (pid == -1 && pipex->cmd_n < pipex->last_cmd)
		error();
	if (pid == 0 && pipex->cmd_n != pipex->last_cmd)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		execute(pipex->argv[pipex->cmd_n], pipex->envp);
	}
	else if (pid == 0 && pipex->cmd_n == pipex->last_cmd)
	{
		dup2(pipex->file_out, STDOUT_FILENO);
		execute(pipex->argv[pipex->cmd_n], pipex->envp);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
	}
}
