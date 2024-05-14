/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboustaj <hboustaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 10:01:45 by hboustaj          #+#    #+#             */
/*   Updated: 2024/05/14 10:45:28 by hboustaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	help(t_game *game, char	*buffer, int i, int j)
{
	if (buffer[j * (game->map->x + 1) + i] == 'P')
	{
		game->num_player++;
		game->p_x = i;
		game->p_y = j;
	}
	else if (buffer[j * (game->map->x + 1) + i] == 'C')
		game->num_coins++;
	else if (buffer[j * (game->map->x + 1) + i] == 'E')
		game->num_exit++;
	game->map->map[j][i] = buffer[j * (game->map->x + 1) + i];
}

void	map_fill_in(t_game *game, char *buffer)
{
	int	i;
	int	j;

	j = 0;
	while (j < game->map->y)
	{
		i = 0;
		game->map->map[j] = (char *)malloc((game->map->x + 1) * sizeof(char));
		if (!game->map->map[j])
			return ;
		while (i < game->map->x)
		{
			help(game, buffer, i, j);
			i++;
		}
		game->map->map[j++][i] = '\0';
	}
}

void	map_spliting(char *buffer, t_game *game)
{
	int	i;

	i = 0;
	game->map->y = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			game->map->y++;
		i++;
	}
	if (buffer[i - 1] != '\n')
		game->map->y++;
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	game->map->x = i;
	if (game->map->x > 51 || game->map->y > 28)
		map_err(buffer, game, "Map is bigger than the screen.\n");
	game->map->map = (char **)malloc((game->map->y) * sizeof (char *));
	if (!game->map->map)
		return ;
	map_fill_in(game, buffer);
	wall_cheker(game, buffer);
	free(buffer);
}

char	**map_init(char *map, t_game *game)
{
	char	*buffer;
	int		i;
	int		fd;

	game->num_coins = 0;
	game->num_exit = 0;
	game->num_player = 0;
	game->move = 0;
	buffer = malloc(1500);
	if (!buffer)
		return (0);
	fd = open(map, O_RDONLY);
	i = read(fd, buffer, 1499);
	if (i == -1)
		return (0);
	buffer[i] = '\0';
	empty_line(buffer, game);
	check_characters(buffer, game);
	map_spliting(buffer, game);
	close(fd);
	return (game->map->map);
}

t_game	*ft_malloc(t_game *game)
{
	game = malloc(sizeof(t_game));
	if (!game)
		ft_error("Error : failed to allocate t_game.");
	game->img = malloc(sizeof(t_img));
	if (!game->img)
	{
		free(game);
		ft_error("Error : failed to allocate t_img.");
	}
	game->map = malloc(sizeof(t_map));
	if (!game->map)
	{
		free(game->img);
		free(game);
		ft_error("Error : failed to allocate t_map.");
	}
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		free(game->map);
		free(game->img);
		free(game);
		ft_error("Error : failed to initiate mxl_int function.");
	}
	return (game);
}
