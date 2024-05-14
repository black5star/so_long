/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floodfill.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboustaj <hboustaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 21:46:07 by hboustaj          #+#    #+#             */
/*   Updated: 2024/05/14 11:00:01 by hboustaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_floodfill(int x, int y, char **map, char c)
{
	if (map && map[y] && map[y][x])
	{
		if ((map[y][x] == 'C' || map[y][x] == 'P' || map[y][x] == '0')
			&& map[y][x] != '1' && map[y][x] != 'E' && c == 'C')
		{
			map[y][x] = 'H';
			ft_floodfill(x + 1, y, map, c);
			ft_floodfill(x - 1, y, map, c);
			ft_floodfill(x, y + 1, map, c);
			ft_floodfill(x, y - 1, map, c);
		}
		else if ((map[y][x] == 'E' || map[y][x] == 'H')
			&& map[y][x] != '1' && c == 'E')
		{
			map[y][x] = '1';
			ft_floodfill(x + 1, y, map, c);
			ft_floodfill(x - 1, y, map, c);
			ft_floodfill(x, y + 1, map, c);
			ft_floodfill(x, y - 1, map, c);
		}
	}
}

char	**duplicate(t_game *game)
{
	char	**dup;
	int		j;

	j = 0;
	dup = (char **) malloc ((game->map->y + 1) * sizeof (char *));
	while (j < game->map->y)
	{
		dup[j] = ft_strdup(game->map->map[j]);
		j++;
	}
	dup[j] = NULL;
	return (dup);
}

void	floodcheck(char **dup, t_game *game)
{
	int	i;
	int	j;

	j = 0;
	while (dup[j])
	{
		i = 0;
		while (dup[j][i])
		{
			if (dup[j][i] == 'C' || dup[j][i] == 'E')
			{
				write(1, "your map is invalid!\n", 21);
				free_dup(dup, game);
				ft_destroy(game);
				ft_free(game);
			}
			i++;
		}
		j++;
	}
}

void	map_cheker(t_game *game)
{
	char	**dup;

	if (game->num_coins == 0 || game->num_player != 1 || game->num_exit != 1)
	{
		write(STDERR_FILENO,
			"Error : your map has invalid number of 'E', 'C' or 'P'.\n", 56);
		ft_destroy(game);
		ft_free(game);
	}
	dup = duplicate(game);
	ft_floodfill(game->p_x, game->p_y, dup, 'C');
	ft_floodfill(game->p_x, game->p_y, dup, 'E');
	floodcheck(dup, game);
	free_dup(dup, game);
}

int	ft_exit(t_game *game)
{
	ft_destroy(game);
	ft_free(game);
	return (0);
}
