/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldatilio <ldatilio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 09:01:24 by ldatilio          #+#    #+#             */
/*   Updated: 2022/02/15 02:19:18 by ldatilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./pipex.h"

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
	free_matrix(path);
	error_cmd_not_found(cmd);
	exit(127);
}

char	**get_cmd(char *arg)
{
	int		i;
	char	**cmd;

	i = 0;
	while (arg[i])
	{
		if (arg[i] == '\'' || arg[i] == '\"')
		{
			i++;
			while (arg[i] != '\'' && arg[i] != '\"' && arg[i] != '\0')
				i++;
		}
		else if (arg[i] == ' ')
			arg[i] = 1;
		i++;
	}
	cmd = ft_split(arg, 1);
	return (cmd);
}
