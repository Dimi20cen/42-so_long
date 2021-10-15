/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zmain.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmylonas <dmylonas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 17:26:15 by dmylonas          #+#    #+#             */
/*   Updated: 2021/10/09 22:46:46 by dmylonas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	before_exiting(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i] != NULL)
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
	mlx_destroy_image(game->win.mlx, game->img.wall);
	mlx_destroy_image(game->win.mlx, game->img.empty_space);
	mlx_destroy_image(game->win.mlx, game->img.player);
	mlx_destroy_image(game->win.mlx, game->img.collectible);
	mlx_destroy_image(game->win.mlx, game->img.exit);
	mlx_destroy_display(game->win.mlx);
	mlx_destroy_window(game->win.mlx, game->win.mlx_win);
	free(game->win.mlx);
}

int	x_button(t_game *game)
{
	before_exiting(game);
	exit(0);
}

void	files_to_image(t_game *game)
{
	int			height;
	int			width;
	int			*height_ptr;
	int			*width_ptr;

	height = 50;
	width = 50;
	height_ptr = &height;
	width_ptr = &width;
	game->img.wall = mlx_xpm_file_to_image (game->win.mlx,
			"elements/wall.xpm", height_ptr, width_ptr);
	game->img.empty_space = mlx_xpm_file_to_image (game->win.mlx,
			"elements/empty_space.xpm", height_ptr, width_ptr);
	game->img.collectible = mlx_xpm_file_to_image (game->win.mlx,
			"elements/collectible.xpm", height_ptr, width_ptr);
	game->img.player = mlx_xpm_file_to_image (game->win.mlx,
			"elements/player.xpm", height_ptr, width_ptr);
	game->img.exit = mlx_xpm_file_to_image (game->win.mlx,
			"elements/exit.xpm", height_ptr, width_ptr);
}

void	lets_game(t_game *game)
{
	game->win.mlx = mlx_init();
	game->win.mlx_win = mlx_new_window(game->win.mlx,
			game->n_of_columns * 50, game->n_of_rows * 50, "GameTime");
	files_to_image(game);
	fill_map(game);
	mlx_key_hook (game->win.mlx_win, movement, game);
	mlx_hook(game->win.mlx_win, 33, 1L << 5, x_button, game);
	mlx_loop (game->win.mlx);
}

int	main(int argc, char *argv[])
{
	t_game	game;

	game.moves = 0;
	check_parameters_from_input(argc, argv);
	game.map = create_map(argv[1], &game);
	check_map_structure(&game);
	lets_game(&game);
	return (0);
}
