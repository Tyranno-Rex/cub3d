/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 13:20:39 by minjinki          #+#    #+#             */
/*   Updated: 2023/08/22 17:24:57 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# define WIDTH 640
# define HEIGHT 480
# define IMG_W 64
# define IMG_H 64

# define W 13
# define A 0
# define S 1
# define D 2
# define ESC 53
# define LEFT 123
# define RIGHT 124
# define KEY_PRESS 2
# define KEY_RELEASE 3
# define KEY_EXIT 17

typedef struct s_xpm
{
	void	*north;
	void	*south;
	void	*west;
	void	*east;

	void	*img;
	int		*addr;
	int		bpp;
	int		endian;
	int		len;
	int		img_w;
	int		img_h;

	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	move_sp;
	double	rot_sp;
}	t_xpm;

typedef struct s_img
{
	// int		floor;
	// int		ceil;

	char	*north;
	char	*south;
	char	*west;
	char	*east;
	void	*tmp;
}	t_img;

typedef struct s_map
{
	char 	*full_path;
	char	**map;
	char	**map_cp;
	char	**map_cp2;
	int		map_len;
	int		width;
	int		height;

	unsigned int floor_color;
	unsigned int cell_color;
	
	unsigned int 	px;
	unsigned int 	py;
	char			pos;
}	t_map;

typedef struct s_color
{
	int R;
	int G;
	int B;
} t_color;

typedef struct s_game
{
	void	*mlx;
	void	*win;

	int		buf[HEIGHT][WIDTH];

	t_img	img;
	t_map	map;
	t_xpm	xpm;
}	t_game;

#endif