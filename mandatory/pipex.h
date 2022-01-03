/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eanastas <eanastas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 18:06:44 by eanastas          #+#    #+#             */
/*   Updated: 2021/12/31 18:36:19 by eanastas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "../libft/libft.h"

typedef struct pipex
{
	int		argc;
	char	**argv;
	char	**envp;
	int		file_in;
	int		file_out;
	int		cmd_n;
	int		last_cmd;
}	t_pipex;

void	error(void);
void	execute(char *argv, char **envp);
void	child_process(t_pipex *pipex);
char	*find_path(char *cmd, char **envp);
void	initialize_pipex(int argc, char **argv, char **envp, t_pipex *pipex);

#endif