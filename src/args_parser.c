/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldatilio <ldatilio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 09:01:24 by ldatilio          #+#    #+#             */
/*   Updated: 2022/02/05 19:21:06 by ldatilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./pipex.h"

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

char	*get_cmd_path(char *cmd)
{
	char	**path;
	char	*temp;
	int		i;

	if (cmd == NULL)
		return (NULL);
	path = ft_split(PATH, ':');
	i = 0;
	while (path[i])
	{
		temp = ft_strjoin(path[i], cmd);
		if (access(temp, F_OK) == 0)
		{
			free_matrix(path);
			return (temp);
		}
		free(temp);
		i++;
	}
	return (NULL);
}

char	**get_cmd(char *argv)
{
	int		i;
	char	**cmd;

	i = 0;
	while (argv[i])
	{
		if (argv[i] == '\'' || argv[i] == '"')
			while (argv[i + 1] == ' ')
				i++;
		else if (argv[i] == ' ')
			argv[i] = ';';
		i++;
	}
	cmd = ft_split(argv, ';');
	return (cmd);
}
