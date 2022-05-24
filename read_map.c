/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masebast <masebast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:11:05 by masebast          #+#    #+#             */
/*   Updated: 2022/05/20 16:54:11 by masebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_height(char *file_name)
{
	int		fd;
	int		height;
	char	*str;

	fd = open(file_name, O_RDONLY, 0);
	height = 0;
	str = get_next_line(fd);
	while (str != NULL)
	{
		height++;
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	return (height);
}

int	get_length(char *file_name)
{
	int		fd;
	int		i;
	int		x;
	char	*str;

	fd = open(file_name, O_RDONLY, 0);
	str = get_next_line(fd);
	i = 0;
	while (str[i] != '\n')
		i++;
	x = i;
	free(str);
	str = get_next_line(fd);
	while (str != NULL)
	{
		i = 0;
		while (str[i] != '\n' && str[i] != '\0')
			i++;
		if (i != x)
			ft_error("Lines");
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	return (i);
}

void	fill_matrix(char *z_line, char *lines)
{
	int	i;

	i = 0;
	while (lines[i] != '\n' && lines[i] != '\0')
	{
		z_line[i] = lines[i];
		i++;
	}
	free(lines);
	z_line[i] = '\0';
}

void	read_file(char *file_name, t_coordinate *data)
{
	int		fd;
	char	*line;
	int		i;

	data->map_lenght = get_length(file_name);
	data->map_height = get_height(file_name);
	data->map_matrix = (char **)malloc(sizeof(char *) * (data->map_height) + 1);
	data->map_matrix[data->map_height] = NULL;
	line = NULL;
	i = 0;
	while (i < data->map_height)
	{
		data->map_matrix[i] = malloc(sizeof(char) * (data->map_lenght + 1));
		i++;
	}
	fd = open(file_name, O_RDONLY, 0);
	i = 0;
	line = get_next_line2(fd, line);
	while (line != NULL)
	{
		fill_matrix(data->map_matrix[i], line);
		line = get_next_line2(fd, line);
		i++;
	}
	close (fd);
}
