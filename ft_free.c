/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboustaj <hboustaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 12:03:33 by hboustaj          #+#    #+#             */
/*   Updated: 2024/04/28 18:11:20 by hboustaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(char *str)
{
	ft_putstr_fd(str, 1);
	write(STDOUT_FILENO, "\n", 1);
	exit(1);
}

void	map_err(char*buffer, t_game *game, char *str)
{
	free(buffer);
	free(game->img);
	free(game->map);
	free(game);
	ft_putstr_fd(str, STDOUT_FILENO);
	ft_error("ERROR : please fix you map's errors.");
}

void	ft_destroy(t_game *game)
{
	mlx_destroy_image (game->mlx, game->img->coin);
	mlx_destroy_image (game->mlx, game->img->exit);
	mlx_destroy_image (game->mlx, game->img->pf);
	mlx_destroy_image (game->mlx, game->img->pl);
	mlx_destroy_image (game->mlx, game->img->pr);
	mlx_destroy_image (game->mlx, game->img->space);
	mlx_destroy_image (game->mlx, game->img->wall);
	mlx_destroy_window(game->mlx, game->window);
}

void	ft_free(t_game *game)
{
	int	j;

	j = 0;
	while (j < game->map->y)
		free(game->map->map[j++]);
	free(game->map->map);
	free(game->map);
	free(game->img);
	exit(0);
}

void	free_dup(char **dup, t_game *game)
{
	int	j;

	j = 0;
	while (j <= game->map->y)
		free(dup[j++]);
	free(dup);
}
