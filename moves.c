/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboustaj <hboustaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 10:27:45 by hboustaj          #+#    #+#             */
/*   Updated: 2024/04/28 18:06:34 by hboustaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	go_up(t_game *game)
{
	if (game->map->map[game->p_y - 1][game->p_x] == 'E' && game->num_coins == 0)
	{
		ft_printmoves(game);
		ft_putstr_fd("YOU WON!\n", STDOUT_FILENO);
		ft_destroy(game);
		ft_free(game);
	}
	if (game->map->map[game->p_y - 1][game->p_x] != '1'
		&& game->map->map[game->p_y -1][game->p_x] != 'E')
	{
		if (game->map->map[game->p_y -1][game->p_x] == 'C')
			game->num_coins--;
		game->p_y -= 1;
		game->map->map[game->p_y + 1][game->p_x] = '0';
		mlx_put_image_to_window(game->mlx, game->window,
			game->img->space, game->p_x * 50, (game->p_y + 1) * 50);
		mlx_put_image_to_window(game->mlx, game->window,
			game->img->pf, game->p_x * 50, game->p_y * 50);
		ft_printmoves(game);
	}
}

void	go_down(t_game *game)
{
	if (game->map->map[game->p_y + 1][game->p_x] == 'E'
		&& game->num_coins == 0)
	{
		ft_printmoves(game);
		ft_putstr_fd("YOU WON!\n", STDOUT_FILENO);
		ft_destroy(game);
		ft_free(game);
	}
	if (game->map->map[game->p_y + 1][game->p_x] != '1'
		&& game->map->map[game->p_y + 1][game->p_x] != 'E')
	{
		if (game->map->map[game->p_y + 1][game->p_x] == 'C')
			game->num_coins--;
		game->p_y += 1;
		game->map->map[game->p_y - 1][game->p_x] = '0';
		mlx_put_image_to_window(game->mlx, game->window,
			game->img->space, game->p_x * 50, (game->p_y - 1) * 50);
		mlx_put_image_to_window(game->mlx, game->window,
			game->img->pf, game->p_x * 50, game->p_y * 50);
		ft_printmoves(game);
	}
}

void	to_right(t_game *game)
{
	if (game->map->map[game->p_y][game->p_x + 1] &&
		game->map->map[game->p_y][game->p_x +1] == 'E' && game->num_coins == 0)
	{
		ft_printmoves(game);
		ft_putstr_fd("YOU WON!\n", STDOUT_FILENO);
		ft_destroy(game);
		ft_free(game);
	}
	if (game->map->map[game->p_y][game->p_x + 1] != '1' &&
		game->map->map[game->p_y][game->p_x + 1] != 'E')
	{
		if (game->map->map[game->p_y][game->p_x + 1] == 'C')
			game->num_coins--;
		game->p_x += 1;
		game->map->map[game->p_y][game->p_x - 1] = '0';
		mlx_put_image_to_window(game->mlx, game->window,
			game->img->space, (game->p_x - 1) * 50, (game->p_y) * 50);
		mlx_put_image_to_window(game->mlx, game->window,
			game->img->pr, game->p_x * 50, game->p_y * 50);
		ft_printmoves(game);
	}
}

void	to_left(t_game *game)
{
	if (game->map->map[game->p_y][game->p_x - 1] &&
		game->map->map[game->p_y][game->p_x - 1] == 'E' && game->num_coins == 0)
	{
		ft_printmoves(game);
		ft_putstr_fd("YOU WON!\n", STDOUT_FILENO);
		ft_destroy(game);
		ft_free(game);
	}
	if (game->map->map[game->p_y][game->p_x - 1] != '1' &&
		game->map->map[game->p_y][game->p_x - 1] != 'E')
	{
		if (game->map->map[game->p_y][game->p_x - 1] == 'C')
			game->num_coins--;
		game->p_x -= 1;
		game->map->map[game->p_y][game->p_x + 1] = '0';
		mlx_put_image_to_window(game->mlx, game->window,
			game->img->space, (game->p_x + 1) * 50, (game->p_y) * 50);
		mlx_put_image_to_window(game->mlx, game->window,
			game->img->pl, game->p_x * 50, game->p_y * 50);
		ft_printmoves(game);
	}
}

int	ft_key_hook(int key_code, t_game *game)
{
	if (key_code == 53)
	{
		ft_destroy(game);
		ft_free(game);
	}
	if (key_code == 13)
		go_up(game);
	if (key_code == 1)
		go_down(game);
	if (key_code == 2)
		to_right(game);
	if (key_code == 0)
		to_left(game);
	return (1);
}
