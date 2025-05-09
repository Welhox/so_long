/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_mvt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber <clundber@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:40:22 by clundber          #+#    #+#             */
/*   Updated: 2024/02/22 21:04:15 by clundber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	player_action(t_data *data)

{
	int	i;
	int	k;

	k = 0;
	i = -1;
	if (data->map[data->pos_y][data->pos_x] == 'C')
	{
		data->c_found++;
		while (++i < data->c_nbr)
		{
			if (data->collect[0]->instances[i].x == data->pos_x * TX_SIZE
				&& data->collect[0]->instances[i].y == (data->pos_y) * TX_SIZE)
			{
				while (k < 4)
					data->collect[k++]->instances[i].z = 2;
				data->map[data->pos_y][data->pos_x] = '0';
			}
		}
	}
	if (data->c_found == data->c_nbr)
		data->exit_ok = true;
	ft_printf("Amount of moves = %d\n", data->mvt_count);
}

void	player_up(t_data *data)

{
	animation_up(data);
	if (data->map[data->pos_y - 1][data->pos_x] == '1')
		return ;
	data->down[0]->instances->y -= TX_SIZE;
	data->down[1]->instances->y -= TX_SIZE;
	data->down[2]->instances->y -= TX_SIZE;
	data->down[3]->instances->y -= TX_SIZE;
	data->up[0]->instances->y -= TX_SIZE;
	data->up[1]->instances->y -= TX_SIZE;
	data->up[2]->instances->y -= TX_SIZE;
	data->up[3]->instances->y -= TX_SIZE;
	data->left[0]->instances->y -= TX_SIZE;
	data->left[1]->instances->y -= TX_SIZE;
	data->left[2]->instances->y -= TX_SIZE;
	data->left[3]->instances->y -= TX_SIZE;
	data->right[0]->instances->y -= TX_SIZE;
	data->right[1]->instances->y -= TX_SIZE;
	data->right[2]->instances->y -= TX_SIZE;
	data->right[3]->instances->y -= TX_SIZE;
	data->pos_y--;
	data->mvt_count++;
	player_action(data);
	if (data->map[data->pos_y][data->pos_x] == 'E' && data->exit_ok == true)
		victory(data);
}

void	player_down(t_data *data)

{
	animation_down(data);
	if (data->map[data->pos_y + 1][data->pos_x] == '1')
		return ;
	data->down[0]->instances->y += TX_SIZE;
	data->down[1]->instances->y += TX_SIZE;
	data->down[2]->instances->y += TX_SIZE;
	data->down[3]->instances->y += TX_SIZE;
	data->up[0]->instances->y += TX_SIZE;
	data->up[1]->instances->y += TX_SIZE;
	data->up[2]->instances->y += TX_SIZE;
	data->up[3]->instances->y += TX_SIZE;
	data->left[0]->instances->y += TX_SIZE;
	data->left[1]->instances->y += TX_SIZE;
	data->right[0]->instances->y += TX_SIZE;
	data->right[1]->instances->y += TX_SIZE;
	data->left[2]->instances->y += TX_SIZE;
	data->left[3]->instances->y += TX_SIZE;
	data->right[2]->instances->y += TX_SIZE;
	data->right[3]->instances->y += TX_SIZE;
	data->pos_y++;
	data->mvt_count++;
	player_action(data);
	if (data->map[data->pos_y][data->pos_x] == 'E' && data->exit_ok == true)
		victory(data);
}

void	player_left(t_data *data)

{
	animation_left(data);
	if (data->map[data->pos_y][data->pos_x - 1] == '1')
		return ;
	data->down[0]->instances->x -= TX_SIZE;
	data->down[1]->instances->x -= TX_SIZE;
	data->down[2]->instances->x -= TX_SIZE;
	data->down[3]->instances->x -= TX_SIZE;
	data->up[0]->instances->x -= TX_SIZE;
	data->up[1]->instances->x -= TX_SIZE;
	data->up[2]->instances->x -= TX_SIZE;
	data->up[3]->instances->x -= TX_SIZE;
	data->left[0]->instances->x -= TX_SIZE;
	data->left[1]->instances->x -= TX_SIZE;
	data->right[0]->instances->x -= TX_SIZE;
	data->right[1]->instances->x -= TX_SIZE;
	data->left[2]->instances->x -= TX_SIZE;
	data->left[3]->instances->x -= TX_SIZE;
	data->right[2]->instances->x -= TX_SIZE;
	data->right[3]->instances->x -= TX_SIZE;
	data->pos_x--;
	data->mvt_count++;
	player_action(data);
	if (data->map[data->pos_y][data->pos_x] == 'E' && data->exit_ok == true)
		victory(data);
}

void	player_right(t_data *data)

{
	animation_right(data);
	if (data->map[data->pos_y][data->pos_x + 1] == '1')
		return ;
	data->down[0]->instances->x += TX_SIZE;
	data->down[1]->instances->x += TX_SIZE;
	data->down[2]->instances->x += TX_SIZE;
	data->down[3]->instances->x += TX_SIZE;
	data->up[0]->instances->x += TX_SIZE;
	data->up[1]->instances->x += TX_SIZE;
	data->up[2]->instances->x += TX_SIZE;
	data->up[3]->instances->x += TX_SIZE;
	data->left[0]->instances->x += TX_SIZE;
	data->left[1]->instances->x += TX_SIZE;
	data->right[0]->instances->x += TX_SIZE;
	data->right[1]->instances->x += TX_SIZE;
	data->left[2]->instances->x += TX_SIZE;
	data->left[3]->instances->x += TX_SIZE;
	data->right[2]->instances->x += TX_SIZE;
	data->right[3]->instances->x += TX_SIZE;
	data->pos_x++;
	data->mvt_count++;
	player_action(data);
	if (data->map[data->pos_y][data->pos_x] == 'E' && data->exit_ok == true)
		victory(data);
}
