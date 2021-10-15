/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmylonas <dmylonas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 22:41:56 by dmylonas          #+#    #+#             */
/*   Updated: 2021/10/09 22:42:09 by dmylonas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill_map_for_p_c_e(t_game *game, int i, int j)
{			
	if (game->map[i][j] == 'P')
	{
		mlx_put_image_to_window (game->win.mlx,
			game->win.mlx_win, game->img.player, j * 50, i * 50);
		game->p_y = i;
		game->p_x = j;
	}
	else if (game->map[i][j] == 'C')
		mlx_put_image_to_window (game->win.mlx,
			game->win.mlx_win, game->img.collectible,
			j * 50, i * 50);
	else if (game->map[i][j] == 'E')
		mlx_put_image_to_window (game->win.mlx,
			game->win.mlx_win, game->img.exit, j * 50, i * 50);
}

void	fill_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->n_of_rows)
	{
		j = 0;
		while (j < game->n_of_columns)
		{
			if (game->map[i][j] == '1')
				mlx_put_image_to_window (game->win.mlx,
					game->win.mlx_win, game->img.wall, j * 50, i * 50);
			else if (game->map[i][j] == '0')
				mlx_put_image_to_window (game->win.mlx, game->win.mlx_win,
					game->img.empty_space, j * 50, i * 50);
			else if (game->map[i][j] == 'P' ||
				game->map[i][j] == 'C' || game->map[i][j] == 'E')
			{
				fill_map_for_p_c_e(game, i, j);
			}
			j++;
		}
		i++;
	}
}
