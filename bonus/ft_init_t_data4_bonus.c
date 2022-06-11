/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_t_data4_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliot <tliot@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 17:29:22 by tliot             #+#    #+#             */
/*   Updated: 2022/06/11 15:53:44 by tliot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_init_all_img_addr2(t_data *data)
{
	ft_new_img_addr(data, "sprite/piece/piece1.xpm", data->piece1);
	ft_new_img_addr(data, "sprite/piece/piece2.xpm", data->piece2);
	ft_new_img_addr(data, "sprite/piece/piece3.xpm", data->piece3);
	ft_new_img_addr(data, "sprite/piece/piece4.xpm", data->piece4);
	ft_new_img_addr(data, "sprite/fond/fond506.xpm", data->fond506);
	ft_new_img_addr(data, "sprite/fond/fond506H.xpm", data->fond506h);
	ft_new_img_addr(data, "sprite/block/herbe1.xpm", data->herbe1);
	ft_new_img_addr(data, "sprite/block/herbe2.xpm", data->herbe2);
	ft_new_img_addr(data, "sprite/block/herbe3.xpm", data->herbe3);
	ft_new_img_addr(data, "sprite/block/herbe4.xpm", data->herbe4);
	ft_new_img_addr(data, "sprite/block/herbeD.xpm", data->herbed);
	ft_new_img_addr(data, "sprite/block/herbeG.xpm", data->herbeg);
}

void	ft_init_all_img_addr3(t_data *data)
{
	ft_new_img_addr(data, "sprite/block/terre1.xpm", data->terre1);
	ft_new_img_addr(data, "sprite/block/terre2.xpm", data->terre2);
	ft_new_img_addr(data, "sprite/block/terre3.xpm", data->terre3);
	ft_new_img_addr(data, "sprite/block/terre4.xpm", data->terre4);
	ft_new_img_addr(data, "sprite/block/terreD.xpm", data->terred);
	ft_new_img_addr(data, "sprite/block/terreG.xpm", data->terreg);
	ft_new_img_addr(data, "sprite/block/blockP1.xpm", data->blockp1);
	ft_new_img_addr(data, "sprite/block/blockP2.xpm", data->blockp2);
	ft_new_img_addr(data, "sprite/block/blockP3.xpm", data->blockp3);
	ft_new_img_addr(data, "sprite/block/blockP4.xpm", data->blockp4);
	ft_new_img_addr(data, "sprite/block/blockB.xpm", data->blockb);
}

void	ft_init_all_img_addr4(t_data *data)
{
	ft_new_img_addr(data, "sprite/block/SVH.xpm", data->svh);
	ft_new_img_addr(data, "sprite/block/SRH.xpm", data->srh);
	ft_new_img_addr(data, "sprite/perso/Piranha1.xpm",
		data->piranha1);
	ft_new_img_addr(data, "sprite/perso/Piranha2.xpm",
		data->piranha2);
	ft_new_img_addr(data, "sprite/perso/Piranha3.xpm",
		data->piranha3);
	ft_new_img_addr(data, "sprite/perso/Piranha4.xpm",
		data->piranha4);
	ft_new_img_addr(data, "sprite/perso/Piranha5.xpm",
		data->piranha5);
	ft_new_img_addr(data, "sprite/perso/Piranha6.xpm",
		data->piranha6);
	ft_new_img_addr(data, "sprite/perso/mario_HD1.xpm",
		data->mario_hd1);
}

void	ft_init_all_img_addr5(t_data *data)
{
	ft_new_img_addr(data, "sprite/perso/mario_HD2.xpm",
		data->mario_hd2);
	ft_new_img_addr(data, "sprite/perso/mario_HD3.xpm",
		data->mario_hd3);
	ft_new_img_addr(data, "sprite/perso/mario_HG1.xpm",
		data->mario_hg1);
	ft_new_img_addr(data, "sprite/perso/mario_HG2.xpm",
		data->mario_hg2);
	ft_new_img_addr(data, "sprite/perso/mario_HG3.xpm",
		data->mario_hg3);
	ft_new_img_addr(data, "sprite/perso/mario_init1.xpm",
		data->mario_init1);
	ft_new_img_addr(data, "sprite/perso/mario_init2.xpm",
		data->mario_init2);
	ft_new_img_addr(data, "sprite/perso/mario_SD1.xpm",
		data->mario_sd1);
}

void	ft_init_all_img_addr(t_data *data)
{
	ft_init_all_img_addr2(data);
	ft_init_all_img_addr3(data);
	ft_init_all_img_addr4(data);
	ft_init_all_img_addr5(data);
	ft_new_img_addr(data, "sprite/perso/mario_SD2.xpm",
		data->mario_sd2);
	ft_new_img_addr(data, "sprite/perso/mario_SD3.xpm",
		data->mario_sd3);
	ft_new_img_addr(data, "sprite/perso/mario_SD4.xpm",
		data->mario_sd4);
	ft_new_img_addr(data, "sprite/perso/mario_SG1.xpm",
		data->mario_sg1);
	ft_new_img_addr(data, "sprite/perso/mario_SG2.xpm",
		data->mario_sg2);
	ft_new_img_addr(data, "sprite/perso/mario_SG3.xpm",
		data->mario_sg3);
	ft_new_img_addr(data, "sprite/perso/mario_SG4.xpm",
		data->mario_sg4);
}
