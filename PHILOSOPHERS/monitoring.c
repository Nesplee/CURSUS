/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 18:26:38 by dinguyen          #+#    #+#             */
/*   Updated: 2025/02/02 17:57:08 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	all_philos_ate_enough(t_philo *philos, t_config *cfg)
{
	int	i;

	i = 0;
	while (i < cfg->num_philos)
	{
		if (philos[i].meals_eaten < cfg->must_eat)
			return (0);
		i++;
	}
	return (1);
}

static int	check_philosopher_status(t_philo *philo, t_config *cfg)
{
	long long	current_time;

	pthread_mutex_lock(&cfg->dead_mutex);
	current_time = get_current_time();
	if (!philo->is_eating && (current_time - philo->last_meal > cfg->t_to_die))
	{
		cfg->dead = 1;
		pthread_mutex_unlock(&cfg->dead_mutex);
		print_status(philo, DIED);
		return (1);
	}
	pthread_mutex_unlock(&cfg->dead_mutex);
	return (0);
}

static int	check_end_conditions(t_philo *philos, t_config *cfg)
{
	int	i;

	i = -1;
	while (++i < cfg->num_philos)
	{
		if (check_philosopher_status(&philos[i], cfg))
			return (1);
	}
	if (cfg->must_eat > 0 && all_philos_ate_enough(philos, cfg))
	{
		pthread_mutex_lock(&cfg->dead_mutex);
		cfg->dead = 1;
		pthread_mutex_unlock(&cfg->dead_mutex);
		return (1);
	}
	return (0);
}

void	*monitor_routine(void *arg)
{
	t_philo		*philos;
	t_config	*cfg;

	philos = (t_philo *)arg;
	cfg = philos[0].config;
	while (!cfg->dead)
	{
		if (check_end_conditions(philos, cfg))
			return (NULL);
		usleep(100);
	}
	return (NULL);
}
