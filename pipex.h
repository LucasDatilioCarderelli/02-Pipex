/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldatilio <ldatilio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 08:58:01 by ldatilio          #+#    #+#             */
/*   Updated: 2022/02/02 16:12:43 by ldatilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <sys/wait.h>
# include <fcntl.h>

# define PATH "/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin"

typedef struct s_data
{
	pid_t	pid;
	int		fd[2];
	int		fdin;
	int		fdout;
}	t_data;

#endif