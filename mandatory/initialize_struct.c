/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eanastas <eanastas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 18:06:38 by eanastas          #+#    #+#             */
/*   Updated: 2021/12/31 18:06:39 by eanastas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
O_WRONLY | O_CREAT | O_TRUNC -> allows to write, create and rewrite into file
*/

void	initialize_pipex(int argc, char **argv, char **envp, t_pipex *pipex)
{
	pipex->file_in = open(argv[1], O_RDONLY, 0777);
	pipex->file_out = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	pipex->cmd_n = 2;
	pipex->argc = argc;
	pipex->argv = argv;
	pipex->envp = envp;
	pipex->last_cmd = pipex->argc - 2;
}
