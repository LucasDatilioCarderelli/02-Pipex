/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldatilio <ldatilio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 19:56:29 by ldatilio          #+#    #+#             */
/*   Updated: 2022/02/02 16:19:24 by ldatilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	error(int e)
{
	perror("\033[31mError\e[0m");
	exit(e);
}

int	main(int argc, char **argv)
{
	t_data	data;

	data.fdin = open(argv[1], O_RDONLY);
	data.fdout = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (data.fdin == -1 || data.fdout == -1)
		error(ENOENT);
	return (0);
}
