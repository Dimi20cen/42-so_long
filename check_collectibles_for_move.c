/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_collectibles_for_move.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmylonas <dmylonas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 14:11:27 by dmylonas          #+#    #+#             */
/*   Updated: 2021/10/11 14:11:55 by dmylonas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_collectibles(t_game *game)
{
	int	i;
	int	j;
	int	found_col;

	i = 0;
	found_col = 0;
	while (i < game->n_of_rows)
	{
		j = 0;
		while (j < game->n_of_columns)
		{
			if (game->map[i][j] == 'C')
				found_col = 1;
			j++;
		}
		i++;
	}
	return (found_col);
}
