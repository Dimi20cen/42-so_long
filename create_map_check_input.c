/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map_check_input.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmylonas <dmylonas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 09:02:39 by dmylonas          #+#    #+#             */
/*   Updated: 2021/10/09 23:35:59 by dmylonas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

void	error_message_cause_no_space(void)
{
	ft_printf("Error\nYooo map is empty or the first line is empty\n");
	exit(-1);
}

char	*create_map_string(char *map_file_input, t_game *game)
{
	char	*map_str;
	int		fd;
	char	*line;

	fd = open(map_file_input, O_RDONLY);
	if (fd == -1)
		exit(-1);
	map_str = get_next_line(fd);
	game->n_of_rows = 1;
	if (map_str == NULL || *map_str == '\n')
		error_message_cause_no_space();
	line = get_next_line(fd);
	while (1)
	{
		if (line == NULL)
			break ;
		map_str = sl_ft_strjoin(map_str, line);
		if (ft_strncmp(line, "\n", 2) != 0)
			game->n_of_rows++;
		free(line);
		line = get_next_line(fd);
	}
	return (map_str);
}

char	**create_map(char *map_file_input, t_game *game)
{
	char	*map_str;
	char	**map;

	map = NULL;
	map_str = create_map_string(map_file_input, game);
	map = ft_split(map_str, '\n');
	free(map_str);
	return (map);
}

void	check_parameters_from_input(int argc, char **argv)
{
	char	*extension;

	if (argc != 2)
	{
		ft_printf("Error\nBrooo you need to give ONE input!\n");
		exit(-1);
	}
	if ((ft_strlen(argv[1]) < 4) || (!ft_strrchr(argv[1], '.')))
	{
		ft_printf("Error\nMust have \"maps/something.ber\" format\n", 2);
		exit(0);
	}
	extension = strrchr(argv[1], '.');
	if (ft_strcmp(extension, ".ber") != 0)
	{
		ft_printf("Error\nYooo the map file needs to have .ber extension!\n");
		exit(-1);
	}
}
