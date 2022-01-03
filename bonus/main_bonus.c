/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eanastas <eanastas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 18:06:39 by eanastas          #+#    #+#             */
/*   Updated: 2021/12/31 18:37:24 by eanastas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

/*
	If we have enought arguments:
		- Initialize out structure which includes opening in && out file
		- copy file_in fd to out pipe
		- create our child processe 
			(all at once -> crutial for cmds such as yes | head)
		- Wait for all child processes to finish
	If not:
		- error msg && exit
*/

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc >= 5)
	{
		initialize_pipex(argc, argv, envp, &pipex);
		dup2(pipex.file_in, STDIN_FILENO);
		while (pipex.cmd_n <= pipex.last_cmd)
		{
			child_process(&pipex);
			pipex.cmd_n++;
		}
		pipex.cmd_n = 2;
		while (pipex.cmd_n++ < pipex.last_cmd)
			waitpid(-1, NULL, 0);
	}
	else
	{
		ft_putstr_fd("Error\nToo few arguments!\n", 2);
		exit(EXIT_FAILURE);
	}
}
