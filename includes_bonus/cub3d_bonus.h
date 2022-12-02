/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 21:49:33 by jfrancis          #+#    #+#             */
/*   Updated: 2022/11/25 00:10:18 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include "../libs/libft/libft.h"
# include "../libs/minilibx-linux/mlx.h"
# include "defines.h"
# include "structs.h"

void	init_data(t_data *data, int argc, char **argv);
int     print_error(char *msg);

//parse
void	parser(t_data *data);
void	fill_arr_textures(t_data *data, char *line, int i);
void	fill_arr_colors(t_data *data, char *line);
void	fill_map(t_data *data, char *line, int i);
void	read_map(t_data *data);
char	**lines(char *file, t_data *data);
int		check_end_of_file(char *file, char *sufx);
void	fill_structures_loop(t_data *data);
void	add_char_lines(t_data *data);

//map_checker
void	map_checker(t_data *data);
void	search_ocurrence_ground(t_data *data);
void	flood_fill(t_data *data, int row, size_t col);
void	count_col(t_data *data, int i);
void	char_change(t_data *data, int row, size_t col, char new_color);
void	Sul (t_data *data, int row, size_t col);
void	Leste (t_data *data, int row, size_t col);
void	checking_color(t_data *data);
void	check_color(char *color);
int		is_open(t_data *data, int row, size_t col);
int		is_space(char c);
void	checking_texture(t_data *data);
int		is_invalid_file_texture(char *texture);
void	checking_texture(t_data *data);

//utils parse
int		check_flags_cardinal_directions(char *line, int counter);
int		check_flags_colors(char *line);

//free
void	free_array(char **arr);

//keys
int		key_press(int key_code, t_data *data);
int		key_release(int key_code, t_data *data);
int		close_window(t_data *data);

//init
int		get_player_pos(t_data *data);
void	init_player(t_data *data);
float	set_player_direction(char c);
void	set_map_size(t_data *data);

//render
void	render_map(t_data *data);
void	render_player(t_data *data);
void	render_rays(t_data *data);
void	render_layer(t_data *data, int color);
void	project_3d_walls(t_data *data);
void	render_background(t_data *data);

// game
int		game_loop(t_data *data);

// utils
int		map_has_wall_at(float x, float y, t_data *data);
int		is_inside_map(float x, float y, t_data *data);
void	draw_line(t_img *img, t_line line);
void	img_pixel_put(t_img *img, int x, int y, int color);
int		get_color(char *color);

//textures
void	init_textures(t_data *data);
void	map_texture(t_data *data, int i, char* texture);
void	get_texture(t_data *data, int i);

// raycast
void	init_ray_data(t_ray_data *ray_data);
void	init_h_data(float ray_angle, t_ray_data *h_data, t_data *data);
void	init_v_data(float ray_angle, t_ray_data *v_data, t_data *data);

void	cast_all_rays(t_data *data);
void	cast_ray(float ray_angle, int strip, t_data *data);

void	normalize_angle(float *angle);
float	distance_btw_ab(float a1, float a2, float b1, float b2);

int		is_ray_facing_down(float angle);
int		is_ray_facing_up(float angle);
int		is_ray_facing_right(float angle);
int		is_ray_facing_left(float angle);

#endif