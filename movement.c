/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmylonas <dmylonas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 22:40:41 by dmylonas          #+#    #+#             */
/*   Updated: 2021/10/11 14:13:59 by dmylonas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	w_movement(t_game *game)
{
	if (game->map[game->p_y - 1][game->p_x] == 'C' ||
		game->map[game->p_y - 1][game->p_x] == '0')
	{
		game->map[game->p_y - 1][game->p_x] = 'P';
		game->map[game->p_y][game->p_x] = '0';
		game->moves++;
		ft_printf("moves: %d\n", game->moves);
	}
	else if (game->map[game->p_y - 1][game->p_x] == '1')
		return ;
	else if (game->map[game->p_y - 1][game->p_x] == 'E')
	{
		if (check_collectibles(game) == 1)
			return ;
		else
		{
			ft_printf("FINITO!\n");
			before_exiting(game);
			exit(0);
		}
	}
	game->p_y--;
}

void	s_movement(t_game *game)
{
	if (game->map[game->p_y + 1][game->p_x] == 'C' ||
		game->map[game->p_y + 1][game->p_x] == '0')
	{
		game->map[game->p_y + 1][game->p_x] = 'P';
		game->map[game->p_y][game->p_x] = '0';
		game->moves++;
		ft_printf("moves: %d\n", game->moves);
	}
	else if (game->map[game->p_y + 1][game->p_x] == '1')
		return ;
	else if (game->map[game->p_y + 1][game->p_x] == 'E')
	{
		if (check_collectibles(game) == 1)
			return ;
		else
		{
			ft_printf("FINITO!\n");
			before_exiting(game);
			exit(0);
		}
	}
	game->p_y++;
}

void	a_movement(t_game *game)
{
	if (game->map[game->p_y][game->p_x - 1] == 'C' ||
		game->map[game->p_y][game->p_x - 1] == '0')
	{
		game->map[game->p_y][game->p_x - 1] = 'P';
		game->map[game->p_y][game->p_x] = '0';
		game->moves++;
		ft_printf("moves: %d\n", game->moves);
	}
	else if (game->map[game->p_y][game->p_x - 1] == '1')
		return ;
	else if (game->map[game->p_y][game->p_x - 1] == 'E')
	{
		if (check_collectibles(game) == 1)
			return ;
		else
		{
			ft_printf("FINITO!\n");
			before_exiting(game);
			exit(0);
		}
	}
	game->p_x--;
}

void	d_movement(t_game *game)
{
	if (game->map[game->p_y][game->p_x + 1] == 'C' ||
		game->map[game->p_y][game->p_x + 1] == '0')
	{
		game->map[game->p_y][game->p_x + 1] = 'P';
		game->map[game->p_y][game->p_x] = '0';
		game->moves++;
		ft_printf("moves: %d\n", game->moves);
	}
	else if (game->map[game->p_y][game->p_x + 1] == '1')
		return ;
	else if (game->map[game->p_y][game->p_x + 1] == 'E')
	{
		if (check_collectibles(game) == 1)
			return ;
		else
		{
			ft_printf("FINITO!\n");
			before_exiting(game);
			exit(0);
		}
	}
	game->p_x++;
}

int	movement(int keycode, t_game *game)
{
	if (keycode == 119)
		w_movement(game);
	else if (keycode == 115)
		s_movement(game);
	else if (keycode == 97)
		a_movement(game);
	else if (keycode == 100)
		d_movement(game);
	else if (keycode == 65307)
	{
		before_exiting(game);
		exit (0);
	}
	fill_map(game);
	return (0);
}
