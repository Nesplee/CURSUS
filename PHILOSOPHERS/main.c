/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 18:13:47 by dinguyen          #+#    #+#             */
/*   Updated: 2025/02/02 20:10:39 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	join_threads(t_philo *philos, t_config *cfg)
{
	int	i;
	int	ret;

	i = 0;
	ret = SUCCESS;
	while (i < cfg->num_philos)
	{
		if (pthread_join(philos[i].thread, NULL) != 0)
			ret = ERROR;
		i++;
	}
	return (ret);
}

static int	start_simulation(t_philo *philos, t_config *cfg)
{
	pthread_t	monitor;
	int			i;

	cfg->start_time = get_current_time();
	i = 0;
	while (i < cfg->num_philos)
	{
		philos[i].last_meal = cfg->start_time;
		i++;
	}
	if (pthread_create(&monitor, NULL, monitor_routine, philos) != 0)
		return (ERROR);
	if (create_threads(philos, cfg) == ERROR)
		return (ERROR);
	pthread_join(monitor, NULL);
	join_threads(philos, cfg);
	return (SUCCESS);
}

int	main(int ac, char **av)
{
	t_config	cfg;
	t_philo		*philos;

	if (parse_args(ac, av, &cfg) == ERROR)
		return (ERROR);
	if (init_all(&cfg, &philos) == ERROR)
		return (ERROR);
	if (start_simulation(philos, &cfg) == ERROR)
		return (ERROR);
	cleanup(philos, &cfg);
	return (SUCCESS);
}
