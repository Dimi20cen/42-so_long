/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmylonas <dmylonas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 09:01:24 by dmylonas          #+#    #+#             */
/*   Updated: 2021/10/09 22:53:31 by dmylonas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_must_have_c_e_p(t_game *game)
{
	int	i;
	int	found[3];

	i = 0;
	while (game->map[i] != NULL)
	{
		if (ft_strchr(game->map[i], 'C') != NULL)
			found[0] = 1;
		if (ft_strchr(game->map[i], 'E') != NULL)
			found[1] = 1;
		if (ft_strchr(game->map[i], 'P') != NULL)
			found[2] = 1;
		i++;
	}
	if (found[0] + found[1] + found[2] != 3)
	{
		ft_printf("Error\nMap needs 1 and C and E and P!\n");
		exit(-1);
	}
}

void	check_rectangular(t_game *game)
{
	int	i;

	i = 1;
	while (game->map[i] != NULL)
	{
		if (ft_strlen(game->map[i - 1]) != ft_strlen(game->map[i]))
		{
			ft_printf("Error\nRow length is uneven!\n");
			exit(-1);
		}
		i++;
	}
}

void	check_only_contain_1_0_c_p_e(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->n_of_rows)
	{
		j = 0;
		while (j < game->n_of_columns)
		{
			if (game->map[i][j] != '1' && game->map[i][j] != '0' &&
			game->map[i][j] != 'C' && game->map[i][j] != 'P' &&
			game->map[i][j] != 'E')
			{
				ft_printf("Error\nMap can only contain: 1, 0, C, P, E!\n");
				exit(-1);
			}
			j++;
		}
		i++;
	}
}

void	check_borders(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->n_of_rows)
	{
		if (game->map[i][0] != '1' ||
		game->map[i][game->n_of_columns - 1] != '1')
		{
			ft_printf("Error\nSide borders should be of value, 1\n");
			exit(-1);
		}
		i++;
	}
	i = 0;
	while (i < game->n_of_columns)
	{
		if (game->map[0][i] != '1' || game->map[game->n_of_rows - 1][i] != '1')
		{
			ft_printf("Error\nUpper and bottom border should be of value, 1\n");
			exit(-1);
		}
		i++;
	}
}

void	check_map_structure(t_game *game)
{
	game->n_of_columns = ft_strlen(game->map[0]);
	check_borders(game);
	check_rectangular(game);
	check_must_have_c_e_p(game);
	check_only_contain_1_0_c_p_e (game);
}
