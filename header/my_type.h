/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_type.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skitsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 18:13:22 by skitsch           #+#    #+#             */
/*   Updated: 2021/01/08 18:14:39 by skitsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_TYPE_H
# define MY_TYPE_H
#include <math.h>
#include <fcntl.h>
#include "../libft/libft.h"
#include "../mlx/mlx.h"

#include <stdio.h>

#define MIN_WIDTH 320
#define MIN_HEIGHT 240
#define MAX_WIDTH 1920
#define MAX_HEIGHT 1080
#define X 1200
#define Y 800

typedef struct	s_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			width;
	int			height;
	double		d;

}				t_data;

typedef struct	s_coord
{
	int			wall_horis_x;
	int			wall_horis_y;
	int			wall_vertical_x;
	int			wall_vertical_y;
	int			collis_x;
	int			collis_y;

}				t_coord;

typedef struct	s_player
{
	int			x;
	int			y;
	int			check;
	// int			pov_ray;
	double		pov;

}				t_player;

typedef struct	s_sprite
{
	double			x;
	double			y;
	double			length;
	double			h;
	// double			left_pov;
	// double			right_pov;
	struct s_sprite	*next;
	struct s_sprite	*prev;

}				t_sprite;

typedef struct	s_sprite_data
{
	double		length;
	int			x;
	int			y;

}				t_sprite_data;


typedef struct	s_sprite_calculation
{
	double		dx;
	double		dy;
	double		distance;
	double		theta;
	double		gamma;
	double		x0_sprite;
	double		y0_sprite;
	double		length;
	double		d_phi;
	double		wall_length;
	int			sp_width;
	int			sp_heigh;
	int			h;
	int			real_h;
	double		step_y;
	double		step_x;
	int			middle_sprite;
	int			ray_pov;
	int			ray_center;
	int			delta_rays;

}				t_sprite_calculation;


typedef struct	s_collis
{
	double		x;
	double		y;
	double		offset;
	int			err;
	t_sprite	*sprite;

}				t_collis;

typedef struct	s_coord_uniq
{
	int			Ax;
	int			Ay;
	int			dx;
	int			dy;

}				t_coord_uniq;

typedef struct	s_coord_horis
{
	double		Ax;
	double		Ay;
	double		dx;
	double		dy;

}				t_coord_horis;

typedef struct	s_coord_vertic
{
	double		Bx;
	double		By;
	double		dx;
	double		dy;

}				t_coord_vertic;

typedef struct	s_data_map
{
	int			map_len_x;
	int			map_len_y;
	int			size_cub;
	char		(*map)[10];

}				t_data_map;

typedef struct	s_data_draw
{
	char		side;
	double		length;
	double		offset;
	int			h;
	int			color;
	int			x_count;

}				t_data_draw;

typedef struct	s_data_angle
{
	double		phi;
	double		new_phi;
	double		d_phi;
	int			count;
	int			*arr_length;

}				t_data_angle;


typedef struct	s_keyboard
{
	int			A;
	int			D;
	int			W;
	int			S;
	int			left;
	int			right;

}				t_keyboard;

typedef struct	s_draw_sprite
{
	int		x;
	int		y;
	int		color;
	double	y_xmp;
	double	x_xmp;

}				t_draw_sprite;

typedef struct	s_flags
{
	int			NO;
	int			SO;
	int			WE;
	int			EA;
	int			S;
	int			F;
	int			C;
	int			R;
	int			summ;
	int			map_start;
	int			map_end;

}				t_flags;

typedef struct	s_my_map
{
	char				*line;
	int					length;
	struct s_my_map		*next;

}				t_my_map;


typedef struct	s_vars
{
	void		*mlx;
	void		*win;
	t_player	player;
	t_data_map	data_map;
	t_keyboard	keyboard;
	t_data		**data_array;
	t_flags		flags;
	t_my_map	*map_lst;
	char		*dir_wall_left;
	char		*dir_wall_right;
	char		*dir_wall_up;
	char		*dir_wall_down;
	char		*dir_sprite;
	char		**map;
	int			length_map_y;
	int			color_floor;
	int			color_ceilling;

}				t_vars;

typedef struct	s_data_input
{
	char				*str;
	struct s_data_input	*next;

}				t_data_input;


t_collis		find_collision(double phi, t_vars *vars);
t_collis		find_block_unique(double phi, t_vars *vars, t_sprite **sprite);
t_collis		find_block_horisontal(t_vars *vars, double phi, t_sprite **sprite);
t_collis		find_block_vertical(t_vars *vars, double phi, t_sprite **sprite);
void			print_line(int x0, int y0, int x1, int y1, t_data *img);
void			draw_ray(double pov, t_player player, char (*map)[10], t_data *img);
t_data_draw		get_length(t_vars *vars, t_data_angle *angle, t_sprite **sprite);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
void			draw_3d(t_vars *vars);
unsigned int	get_color(t_data data, int y, double offset, int h);
int				add_sprite(t_sprite **sprite_start, double x, double y, t_player player);
void			clear_sprite(t_sprite **sprite_start);
unsigned int	get_color_sprite(t_data data, int y, int x);
void			get_sprite_ray(t_player *player, t_data_angle *angle, t_sprite *sprite, t_data **data_array);
void			get_calc(t_sprite *sprite, t_sprite_calculation *calc, t_player *player, t_data **data_array);
void			draw_sprite(t_sprite_calculation *calc, t_data **data_array, t_data_angle *angle);
int				get_next_line(int fd, char **line);
int				parser(int argc, char **argv, t_vars *vars);
int				get_param(t_vars *vars, t_data_input *input_lst);
int				get_screen_param(char *line, t_vars *vars);
int				get_north_texture(char *line, t_vars *vars);
int				get_south_texture(char *line, t_vars *vars);
int				get_west_texture(char *line, t_vars *vars);
int				get_east_texture(char *line, t_vars *vars);
int				get_sprite_texture(char *line, t_vars *vars);
int				get_S(char *line, t_vars *vars);
int				make_malloc_vars(t_vars *vars);
int				get_floor_color(char *line, t_vars *vars);
int				get_ceilling_color(char *line, t_vars *vars);
int				num_screen_param(char **screen);
void			clear_param(char **screen);
int				get_map_lst(char *line, t_vars *vars);
void			clear_map_lst(t_vars *vars);
int				get_map(t_vars *vars);
int				check_map(t_vars *vars);
int				make_screenshot(t_vars *vars, char **argv);
int				get_img(t_vars *vars);

#endif
