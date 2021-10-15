/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmylonas <dmylonas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 10:41:37 by dmylonas          #+#    #+#             */
/*   Updated: 2021/10/11 14:13:00 by dmylonas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include "Libft/libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_window
{
	void	*mlx;
	void	*mlx_win;
}			t_window;

typedef struct s_img
{
	void	*wall;
	void	*empty_space;
	void	*collectible;
	void	*player;
	void	*exit;
}			t_img;

typedef struct s_game
{
	int			n_of_rows;
	int			n_of_columns;
	int			p_x;
	int			p_y;
	int			moves;
	char		**map;
	t_img		img;
	t_window	win;
}		t_game;

char	*sl_ft_strjoin(char *s1, char const *s2);

char	*create_map_string(char *map_file_input, t_game *game);
char	**create_map(char *map_file_input, t_game *game);
void	check_parameters_from_input(int argc, char **argv);

void	check_must_have_c_e_p(t_game *game);
void	check_rectangular(t_game *game);
void	check_only_contain_1_0_c_p_e(t_game *game);
void	check_borders(t_game *game);
void	check_map_structure(t_game *game);

void	fill_map(t_game *game);

int		movement(int keycode, t_game *game);
int		check_collectibles(t_game *game);

void	before_exiting(t_game *game);

#endif