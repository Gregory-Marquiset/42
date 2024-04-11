/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 22:26:52 by gmarquis          #+#    #+#             */
/*   Updated: 2024/04/11 03:41:02 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_init_data(t_data *data)
{
	data->fd_1 = 0;
	data->fd_2 = 0;
	data->path = NULL;
	data->path_split = NULL;
	data->pipe = 0;
	data->cmd_split = NULL;
}

void	ft_find_access(t_data *data, char *cmd, char **envp)
{
	int	i;

	i = 0;
	while (data->path_split[i])
	{
		data->path = ft_strjoin(data->path_split[i], "/", 1);
		data->path = ft_strjoin(data->path, cmd, 1);
		if (access(data->path, 0) == 0)
			execve(data->path, data->cmd_split, envp);
		free (data->path);
		i++;
	}
}

char	*ft_find_start(char **envp, char *to_find)
{
	int		i;

	i = 0;
	while (envp[i])
	{
		if(!ft_strncmp(envp[i], to_find, 5))
			return (envp[i] + 5);
		i++;
	}
	return (NULL);
}

void	ft_child(t_data *data, char *cmd, char **envp, int flag)
{
	data->cmd_split = ft_split(cmd, ' ', ' ');
	if (flag == 0)
	{
		dup2(data->fd_1, 0);
		dup2(data->pipe[1], 1);
	}
	if (flag == 1)
	{
		dup2(data->fd_2, 1);
		dup2(data->pipe[0], 0);
	}
	if (access(cmd, 0) == 0)
		execve(cmd, data->cmd_split, envp);
	data->path = ft_find_start(envp, "PATH=");
	data->path_split = ft_split(data->path, ':', ':');
	ft_find_access(data, cmd, envp);
	exit(0);
}

int	main(int argc, char **argv, char **envp)
{
	t_data	data;
	int	i;
	int pid;

	if (argc != 5)
		return (ft_exit(2,
				"Error: Bad argument format (./pipex file cmd cmd file)\n"), 0);
	ft_init_data(&data);
	data.fd_1 = open(argv[1], O_RDONLY);
	if (data.fd_1 == -1)
		return (ft_out(&data, "Error: invalid fd_1\n", 0), 0);
	data.fd_2 = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (data.fd_2 == -1)
		return (ft_out(&data, "Error: invalid fd_2\n", 1), 0);
	data.pipe = malloc(2 * sizeof(int));
	if (pipe(data.pipe) == -1)
		return (ft_out(&data, "Error: echec pipe\n", 2), 0);
	i = 0;
	while (i < argc - 3)
	{
		pid = fork();
		if (pid == 0 && i == 0)
			ft_child(&data, argv[2], envp, i);
		else if (pid == 0 && i == 1)
			ft_child(&data, argv[3], envp, i);
		i++;
	}
	while (i > 0)
	{
		waitpid(0, NULL, 0);
		i--;
	}
	return (0);
}
