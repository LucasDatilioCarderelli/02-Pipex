/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldatilio <ldatilio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 10:42:53 by ldatilio          #+#    #+#             */
/*   Updated: 2022/02/10 10:43:46 by ldatilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error(int e)
{
	perror("\033[31mError\e[0m");
	exit(e);
}

void	error_cmd_not_found(char *cmd)
{
	write(2, "\033[31mError\e[0m: ", 16);
	write(2, "command not found: ", 19);
	write(2, cmd, 10);
	write(2, "\n", 2);
}

int	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
	matrix = NULL;
	return (0);
}
