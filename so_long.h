/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboustaj <hboustaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 23:00:16 by hboustaj          #+#    #+#             */
/*   Updated: 2024/04/30 17:37:30 by hboustaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>

# define PIXEL 64

typedef struct s_img
{
	void	*wall;
	void	*space;
	void	*coin;
	void	*exit;
	void	*pf;
	void	*pl;
	void	*pr;
}	t_img;

typedef struct s_map
{
	char	**map;
	int		x;
	int		y;
}	t_map;

typedef struct s_game
{
	void	*mlx;
	void	*window;
	int		move;
	int		num_player;
	int		num_coins;
	int		num_exit;
	int		p_x;
	int		p_y;
	t_map	*map;
	t_img	*img;
}	t_game;

void	map_fill_in(t_game *game, char *buffer);
void	map_spliting(char *buffer, t_game *game);
char	**map_init(char *map, t_game *game);
t_game	*game_init(char *map);
t_img	*path_init(t_game *game);
int		put_image(t_game *game, int i, int j);
void	draw_map(t_game *game);
void	check_files(char *s);
void	go_up(t_game *game);
void	go_down(t_game *game);
void	to_right(t_game *game);
void	to_left(t_game *game);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *s);
int		ft_key_hook(int key_code, t_game *game);
void	ft_error(char *str);
void	ft_free(t_game *game);
void	help(t_game *game, char	*buffer, int i, int j);
void	ft_destroy(t_game *game);
void	map_err(char *buffer, t_game *game, char *str);
void	empty_line(char *buffer, t_game *game);
void	wall_cheker(t_game *game, char *buffer);
void	check_characters(char *s, t_game *game);
void	map_cheker(t_game *game);
void	floodcheck(char **dup, t_game *game);
void	free_dup(char **dup, t_game *game);
char	**duplicate(t_game *game);
char	*ft_strdup(const char *s1);
void	ft_floodfill(int x, int y, char **map, char c);
t_game	*ft_malloc(t_game *game);
void	ft_printmoves(t_game *game);

#endif
