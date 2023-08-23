/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 17:52:58 by minjinki          #+#    #+#             */
/*   Updated: 2023/08/23 16:18:49 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

// void	paint(t_game *game)
// {
// 	int	x;
// 	int	y;

// 	y = 0;
// 	while (y < HEIGHT / 2)
// 	{
// 		x = 0;
// 		while (x < WIDTH)
// 		{
// 			mlx_pixel_put(game->mlx, game->win, x, y, game->map.cell_color);
// 			mlx_pixel_put(game->mlx, game->win, x, HEIGHT - y - 1, game->map.floor_color);
// 			x++;
// 		}
// 		y++;
// 	}
// }

void	paint_floor_ceiling(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT / 2)
	{
		x = 0;
		while (x < WIDTH)
		{
			game->buf[y][x] = game->map.cell_color;
			game->buf[HEIGHT - y - 1][x] = game->map.floor_color;
			x++;
		}
		y++;
	}
}

void	set_side_dist(t_xpm *xpm)
{
	if (xpm->raydir_x < 0)
	{
		xpm->step_x = -1;
		xpm->sidedist_x = (xpm->pos_x - xpm->map_x) * xpm->deltadist_x;
	}
	else
	{
		xpm->step_x = 1;
		xpm->sidedist_x = (xpm->map_x + 1.0 - xpm->pos_x) * xpm->deltadist_x;
	}
	if (xpm->raydir_y < 0)
	{
		xpm->step_y = -1;
		xpm->sidedist_y = (xpm->pos_y - xpm->map_y) * xpm->deltadist_y;
	}
	else
	{
		xpm->step_y = 1;
		xpm->sidedist_y = (xpm->map_y + 1.0 - xpm->pos_y) * xpm->deltadist_y;
	}
}

void	init_ray(t_game *game, int i)
{
	game->xpm.camera_x = 2 * i / (double)WIDTH - 1;
	game->xpm.raydir_x = game->xpm.dir_x + game->xpm.plane_x * game->xpm.camera_x;
	game->xpm.raydir_y = game->xpm.dir_y + game->xpm.plane_y * game->xpm.camera_x;
	game->xpm.map_x = (int)game->xpm.pos_x;
	game->xpm.map_y = (int)game->xpm.pos_y;
	game->xpm.deltadist_x = fabs(1 / game->xpm.raydir_x);
	game->xpm.deltadist_y = fabs(1 / game->xpm.raydir_y);
	game->xpm.hit = 0;
	set_side_dist(&(game->xpm));
}

int	render_img(t_game *game)
{
	int	i;

	paint_floor_ceiling(game);
	i = 0;
	while (i < WIDTH)
	{
		init_ray(game, i);
		cal_dda(game);
	}
	// ray_casting(game);
	//paint(game); // ray_casting에서 buf에 저장한 내용을 기반으로 pixel_put
	return (0);
}
