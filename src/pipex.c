/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldatilio <ldatilio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 19:56:29 by ldatilio          #+#    #+#             */
/*   Updated: 2022/02/10 15:05:10 by ldatilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./pipex.h"

void	parent_process(t_data *data)
{
	char	**cmd;
	char	*cmd_path;

	cmd = get_cmd(data->argv[3]);
	cmd_path = get_cmd_path(cmd[0]);
	close(data->fd[1]);
	dup2(data->fd[0], STDIN_FILENO);
	close(data->fd[0]);
	dup2(data->fdout, STDOUT_FILENO);
	close(data->fdout);
	execve(cmd_path, cmd, data->envp);
}

void	child_process(t_data *data)
{
	char	**cmd;
	char	*cmd_path;

	cmd = get_cmd(data->argv[2]);
	cmd_path = get_cmd_path(cmd[0]);
	close(data->fd[0]);
	dup2(data->fdin, STDIN_FILENO);
	close(data->fdin);
	dup2(data->fd[1], STDOUT_FILENO);
	close(data->fd[1]);
	execve(cmd_path, cmd, data->envp);
}

void	pipex(t_data *data)
{
	if (pipe(data->fd) == -1)
		error(errno);
	data->pid = fork();
	if (data->pid == -1)
		error(errno);
	if (data->pid == 0)
	{
		child_process(data);
	}
	else
	{
		waitpid(data->pid, NULL, 0);
		parent_process(data);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	if (argc != 5)
	{
		write(2, "Error: Invalid argument\n", 25);
		exit(EINVAL);
	}
	data.fdin = open(argv[1], O_RDONLY, 0644);
	data.fdout = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (data.fdin == -1 || data.fdout == -1)
		error(errno);
	data.argc = argc;
	data.argv = argv;
	data.envp = envp;
	pipex(&data);
	return (0);
}
