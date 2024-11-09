/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 12:09:37 by zait-bel          #+#    #+#             */
/*   Updated: 2024/11/06 11:34:43 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>
# include <unistd.h>
# include <math.h>
# include ".MLX42.h"

# define TILE_SIZE 50
# define SCREEN_WIDTH 1080
# define SCREEN_HEIGHT 609
# define SPEED 4

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct intersection
{
	double	x;
	double	y;
	double	dist;
	bool	ver_hit;
}			t_inter;

// ***************************

typedef struct player
{
	double	x;
	double	y;
	double	angle;
	int		wd;
	int		ard;
	int		td;	
}			t_player;

// ***************************

typedef struct s_heap	t_heap;

struct s_heap
{
	void	*ptr;
	t_heap	*next;
};

// ***************************

typedef struct s_data
{
	mlx_texture_t	*no_texture;
	mlx_texture_t	*so_texture;
	mlx_texture_t	*we_texture;
	mlx_texture_t	*ea_texture;
	mlx_image_t		*no_image_texture;
	mlx_image_t		*so_image_texture;
	mlx_image_t		*we_image_texture;
	mlx_image_t		*ea_image_texture;
	mlx_image_t		*tp;
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			**map;
	int				f_c;
	int				c_color;
	int				height;
	size_t			width;
	int				wall_x;
	int				tex_width;
	int				tex_height;
	int				text_x;
	double			step;
	double			text_pos;
	double			text_y;
}					t_data;

// ***************************

typedef struct rays
{
	double		dis;
	bool		is_up;
	bool		is_down;
	bool		is_left;
	bool		is_right;
	int			i;
	uint32_t	color;
}				t_ray;

// ***************************

typedef struct cube
{
	t_heap			*heap;
	mlx_t			*mlx;
	mlx_image_t		*image;
	t_player		*player;
	t_inter			*hit;
	t_data			*data;
	t_ray			*ray;
	int				cursor_hidden;
	double			fov_angle;
}					t_cube;

// ***************************

typedef struct s_line_y
{
	long	from;
	long	to;
}		t_line_y;

// ***************************

char			*ft_strjoin(char *s1, char *s2);
char			*ft_substr(const char *s, unsigned int start, size_t len);
size_t			ft_strlen(const char *str);
char			*ft_strdup(const char *src);
char			*get_next_line(int fd);
char			**ft_split(char const *s, char c);
void			ft_error_message(char *mess);
void			check_file_isvalid(char *file);
char			**ft_read_map(char *file);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strtrim(const char *s1, const char *set);
void			ft_free_leak(char **str);
int				ft_atoi(const char *str);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
/*______________________ parsing map_____________*/

void			get_data(t_data *args, char **file, int *r);
char			*check_last_line(char **file);
char			**get_map_filled_with_spaces(char **file, t_data *args);
int				check_line_is_empty(char *line);
void			check_first_line(char *line);
void			check_map(char **file, t_data *args);
void			init_data(t_data *args);
void			check_params(t_data args);
void			check_elements(t_data *args);
void			assign_color(t_data *args, char *line, char **tmp2);
void			is_num(char *str);
void			check_map_round_byones(t_data *args);
void			ivalid_lelement(char *str);
void			rep_spaseses_to_ones(t_data *args);
t_data			*ft_parsing(char **av);

/*-----------garbege collecter---------------*/
void			clearheap(t_heap **node);
void			*mohi_bel_malloc(size_t __size);

/*-----------raycasting---------------*/
void			render_3d(void *param);
void			handle_key_input(mlx_key_data_t keydata, void *param);
t_inter			find_vertical_intersection(t_cube *cube, double angle);
t_inter			find_horizontal_intersection(t_cube *cube, double angle);
void			initialize_position(t_data *data, double *x, double *y);
bool			is_wall(size_t x, int y, t_cube *cub);
void			render_wall(t_cube *cube, double x, double ray);
void			render_minimap(t_cube *cube);
void			bresenham_line(long x, t_line_y line, t_cube *cub, long color);
int				get_sign(int a, int b);
void			calculate_closest_ray(t_inter ch, t_inter cv, t_cube *cube);
void			draw_player(void *param);
void			put_pixel_safe(mlx_image_t *img, long x, long y, long color);
void			move_player(t_cube *cube);
bool			check_boundaries(double x, double y, t_cube *cube);
double			normalize_angle(double angle);
void			cal_wall_dimen(t_cube *cube, int *from_y, int *to_y,
					double *w_height);
/*-------------------------textures---------------------------*/

void			sel_calculate_texture(t_cube *cube, mlx_image_t *current_tex);
void			calculate_tex_pos(t_cube *cube, mlx_image_t *tex, \
					double w_height, int f_y);
mlx_image_t		*find_texture(t_cube *cube);
uint32_t		get_texture_pixel(mlx_image_t *texture, int x, int y);
void			load_textures(t_cube *cube);
void			apply_shadow(uint32_t *color, t_cube *cube, \
					double max_distance);
void			ft_texture_to_image(t_cube *cube);

/*-------------------------------------------------------*/
void			cal_wall_dimen(t_cube *cube, int *from_y, int *to_y,
					double *w_height);
void			ft_clear_image(mlx_image_t *img);
void			ft_mouse(double xpos, double ypos, void *param);
void			ft_close(void *param);
int				mlx_data_init(t_cube *cube);
int				data_init(t_cube *cube, t_player *player, \
					t_inter *hit, t_ray *ray);
mlx_texture_t	*my_mlx_load_png(char *path);
mlx_image_t		*my_mlx_texture_to_image(void *mlx, mlx_texture_t *texture);
t_cube			*get_cub(t_cube *cub);
double			update_angle(t_cube *cube);
void			exact_angle(t_cube *cube, int i, int j, double *angle);
#endif