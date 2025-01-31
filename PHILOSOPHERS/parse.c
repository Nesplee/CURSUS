/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 18:06:05 by dinguyen          #+#    #+#             */
/*   Updated: 2025/01/31 18:35:43 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	is_valid(t_config *cfg)
{
	if (cfg->num_philos < 1)
		return (ERROR);
	if (cfg->t_to_die < 0 || cfg->t_to_eat < 0 || cfg->t_to_sleep < 0)
		return (ERROR);
	return (SUCCESS);
}

int	parse_args(int ac, char **av, t_config *cfg)
{
	if (ac != 5 && ac != 6)
		return (ERROR);
	cfg->num_philos = ft_atoi(av[1]);
	cfg->t_to_die = ft_atoi(av[2]);
	cfg->t_to_eat = ft_atoi(av[3]);
	cfg->t_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		cfg->must_eat = ft_atoi(av[5]);
	else
		cfg->must_eat = -1;
	cfg->start_time = 0;
	cfg->dead = 0;
	return (is_valid(cfg));
}
