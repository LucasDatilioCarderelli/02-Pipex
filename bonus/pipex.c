/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldatilio <ldatilio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 19:56:29 by ldatilio          #+#    #+#             */
/*   Updated: 2022/02/14 14:00:03 by ldatilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./pipex.h"

void	exec_cmd(t_data *data, int i)
{
	char	**cmd;
	char	*cmd_path;

	cmd = get_cmd(data->argv[i + 2]);
	cmd_path = get_cmd_path(cmd[0]);
	if (i == data->qnt_cmds - 1)
		dup2(data->fdout, STDOUT_FILENO);
	else
		dup2(data->fd[1], STDOUT_FILENO);
	close(data->fdout);
	close(data->fd[1]);
	execve(cmd_path, cmd, data->envp);
}

void	pipex(t_data *data)
{
	int	i;

	dup2(data->fdin, STDIN_FILENO);
	close(data->fdin);
	i = -1;
	while (++i < data->qnt_cmds)
	{
		if (i > 0)
		{
			dup2(data->fd[0], STDIN_FILENO);
			close(data->fd[0]);
		}
		if (pipe(data->fd) == -1)
			error(errno);
		data->pid = fork();
		if (data->pid == -1)
			error(errno);
		if (data->pid == 0)
			exec_cmd(data, i);
		waitpid(data->pid, NULL, 0);
		close(data->fd[1]);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	if (argc <= 3)
	{
		write(2, "Error: Invalid argument\n", 25);
		exit(EINVAL);
	}
	data.fdin = open(argv[1], O_RDONLY, 0644);
	data.fdout = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (data.fdin == -1 || data.fdout == -1)
		error(errno);
	data.qnt_cmds = argc - 3;
	data.argc = argc;
	data.argv = argv;
	data.envp = envp;
	pipex(&data);
	close(data.fdin);
	close(data.fdout);
	return (0);
}
