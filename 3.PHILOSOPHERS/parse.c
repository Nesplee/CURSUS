/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 18:06:05 by dinguyen          #+#    #+#             */
/*   Updated: 2025/02/02 20:39:53 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	is_valid(t_config *cfg)
{
	if (cfg->num_philos < 1)
		return (ERROR);
	if (cfg->t_to_die < 60)
		return (ERROR);
	if (cfg->t_to_eat < 60)
		return (ERROR);
	if (cfg->t_to_sleep < 60)
		return (ERROR);
	if (cfg->must_eat == 0)
		return (ERROR);
	return (SUCCESS);
}

int	parse_args(int ac, char **av, t_config *cfg)
{
	int	i;

	if (ac != 5 && ac != 6)
		return (ERROR);
	i = 1;
	while (i < ac)
	{
		if (!ft_is_number(av[i]))
			return (ERROR);
		i++;
	}
	cfg->num_philos = ft_atoi(av[1]);
	cfg->t_to_die = ft_atoi(av[2]);
	cfg->t_to_eat = ft_atoi(av[3]);
	cfg->t_to_sleep = ft_atoi(av[4]);
	cfg->must_eat = -1;
	if (ac == 6)
		cfg->must_eat = ft_atoi(av[5]);
	cfg->start_time = 0;
	cfg->dead = 0;
	return (is_valid(cfg));
}

void	ft_usleep(long long time_to_wait)
{
	long long	start_time;
	long long	current_time;
	long long	elapsed_time;

	start_time = get_current_time();
	while (1)
	{
		current_time = get_current_time();
		elapsed_time = current_time - start_time;
		if (elapsed_time >= time_to_wait)
			break ;
		usleep(100);
	}
}
