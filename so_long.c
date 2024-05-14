/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboustaj <hboustaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 23:00:04 by hboustaj          #+#    #+#             */
/*   Updated: 2024/05/14 11:01:46 by hboustaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_printmoves(t_game *game)
{
	game->move++;
	ft_putstr_fd("Moves : ", STDOUT_FILENO);
	ft_putnbr_fd(game->move, STDOUT_FILENO);
	ft_putstr_fd("\n", STDOUT_FILENO);
}

int	put_image(t_game *game, int i, int j)
{
	if (game->map->map[j][i] == '1')
		mlx_put_image_to_window(game->mlx, game->window,
			game->img->wall, i * 50, j * 50);
	else if (game->map->map[j][i] == '0')
		mlx_put_image_to_window(game->mlx, game->window,
			game->img->space, i * 50, j * 50);
	else if (game->map->map[j][i] == 'P')
		mlx_put_image_to_window(game->mlx, game->window,
			game->img->pf, i * 50, j * 50);
	else if (game->map->map[j][i] == 'C')
		mlx_put_image_to_window(game->mlx, game->window,
			game->img->coin, i * 50, j * 50);
	else if (game->map->map[j][i] == 'E')
		mlx_put_image_to_window(game->mlx, game->window,
			game->img->exit, i * 50, j * 50);
	i++;
	return (i);
}

void	draw_map(t_game *game)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	while (j < (game->map->y))
	{
		while (i < (game->map->x))
			i = put_image(game, i, j);
		j++;
		i = 0;
	}
}

t_game	*game_init(char *map)
{
	t_game	*game;

	game = NULL;
	game = ft_malloc(game);
	game->map->map = map_init(map, game);
	if (!game->map->map)
	{
		free(game->map);
		free(game->img);
		free(game);
		ft_error("Error : malloc failure.");
	}
	game->img = path_init(game);
	game->window = mlx_new_window(game->mlx,
			game->map->x * 50, game->map->y * 50, "so_long");
	if (!game->window)
		ft_free(game);
	return (game);
}

int	main(int argc, char *argv[])
{
	t_game	*game;

	if (argc != 2)
		ft_error("Error : Your program should takes two arguments.");
	if (access(argv[1], F_OK | R_OK) == -1)
		ft_error("Error : You don't have access to this file.");
	check_files(argv[1]);
	game = game_init(argv[1]);
	map_cheker(game);
	draw_map(game);
	mlx_hook(game->window, 2, (1L << 0), ft_key_hook, game);
	mlx_hook(game->window, 17, 0, ft_exit, game);
	mlx_loop(game->mlx);
	return (0);
}
