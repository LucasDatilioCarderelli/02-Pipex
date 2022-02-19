/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldatilio <ldatilio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 08:58:01 by ldatilio          #+#    #+#             */
/*   Updated: 2022/02/17 19:56:21 by ldatilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>
# include "../utils/utils.h"

# define PATH "/usr/local/sbin/:/usr/local/bin/:\
/usr/sbin/:/usr/bin/:/sbin/:/bin/"

typedef struct s_data
{
	pid_t	pid;
	int		fd[2];
	int		fdin;
	int		fdout;
	int		argc;
	char	**argv;
	char	**envp;
}	t_data;

void	error(int e);
void	error_cmd_not_found(char *cmd);
int		free_matrix(char **matrix);
char	*get_cmd_path(char *cmd);
char	**get_cmd(char *argv);

#endif
