/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboustaj <hboustaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 09:56:33 by hboustaj          #+#    #+#             */
/*   Updated: 2024/05/05 09:51:20 by hboustaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	empty_line(char *buffer, t_game *game)
{
	int	i;

	i = 0;
	if (buffer[i])
	{
		if (buffer[i] == '\n')
			map_err(buffer, game, "Empty line error.\n");
		while (buffer[i + 1])
		{
			if (buffer[i] == '\n' && buffer[i + 1] == '\n')
				map_err(buffer, game, "Empty line error.\n");
			i++;
		}
	}
}

void	check_characters(char *s, t_game *game)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			i++;
		if (s[i] != '0' && s[i] != '1' && s[i] != 'P'
			&& s[i] != 'C' && s[i] != 'E')
			map_err(s, game, "Your map has unknown characters.\n");
		i++;
	}
}

void	wall_cheker(t_game *game, char *buffer)
{
	int	i;
	int	j;

	j = -1;
	while (game->map->map[++j] && j < game->map->y)
	{
		i = -1;
		if (j == 0 || j == game->map->y - 1)
		{
			while (++i < game->map->x)
				if (game->map->map[j][i] != '1')
					map_err(buffer, game,
						"Your map is not surrounded by walls.\n");
		}
		if (game->map->map[j][0] != '1'
			|| game->map->map[j][game->map->x - 1] != '1')
			map_err(buffer, game, "Your map is not surrounded by walls.\n");
	}
}

void	check_files(char *s)
{
	int	len;

	len = ft_strlen(s);
	if (!ft_strncmp(s + (len - 9), "maps/.ber", len)
		|| ft_strncmp(s + ft_strlen(s) - 4, ".ber", 4))
		ft_error("Error : Your map file is invalid.");
	if (access("./textures/coin.xpm", F_OK | R_OK) == -1
		|| access("./textures/exit.xpm", F_OK | R_OK) == -1
		|| access("./textures/player.xpm", F_OK | R_OK) == -1
		|| access("./textures/to_left.xpm", F_OK | R_OK) == -1
		|| access("./textures/to_right.xpm", F_OK | R_OK) == -1
		|| access("./textures/wall.xpm", F_OK | R_OK) == -1
		|| access("./textures/space.xpm", F_OK | R_OK) == -1)
		ft_error("Error : You don't have access to some textures file(s).");
}

t_img	*path_init(t_game *game)
{
	int	x;
	int	y;

	game->img->coin = mlx_xpm_file_to_image
		(game->mlx, "./textures/coin.xpm", &x, &y);
	game->img->exit = mlx_xpm_file_to_image
		(game->mlx, "./textures/exit.xpm", &x, &y);
	game->img->pf = mlx_xpm_file_to_image
		(game->mlx, "./textures/player.xpm", &x, &y);
	game->img->pl = mlx_xpm_file_to_image
		(game->mlx, "./textures/to_left.xpm", &x, &y);
	game->img->pr = mlx_xpm_file_to_image
		(game->mlx, "./textures/to_right.xpm", &x, &y);
	game->img->wall = mlx_xpm_file_to_image
		(game->mlx, "./textures/wall.xpm", &x, &y);
	game->img->space = mlx_xpm_file_to_image
		(game->mlx, "./textures/space.xpm", &x, &y);
	if (!game->img->coin || !game->img->exit || !game->img->pf
		|| !game->img->pl || !game->img->pr || !game->img->space
		|| !game->img->space || !game->img->wall)
		img_err("Error : .xpm is empty.\n", game);
	return (game->img);
}
