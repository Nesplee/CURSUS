/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 18:26:38 by dinguyen          #+#    #+#             */
/*   Updated: 2025/01/31 20:10:31 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	check_philosopher_status(t_philo *philo, t_config *cfg)
{
	long long	current_time;

	current_time = get_current_time();
	pthread_mutex_lock(&cfg->dead_mutex);
	if (current_time - philo->last_meal > cfg->t_to_die && !cfg->dead)
	{
		cfg->dead = 1;
		pthread_mutex_unlock(&cfg->dead_mutex);
		print_status(philo, DIED);
		return (1);
	}
	pthread_mutex_unlock(&cfg->dead_mutex);
	return (0);
}

static int	check_philosophers_meals(t_philo *philos, t_config *cfg)
{
	int	i;
	int	all_ate;

	if (cfg->must_eat <= 0)
		return (0);
	pthread_mutex_lock(&cfg->dead_mutex);
	i = -1;
	all_ate = 1;
	while (++i < cfg->num_philos)
	{
		if (philos[i].meals_eaten < cfg->must_eat)
		{
			all_ate = 0;
			break ;
		}
	}
	if (all_ate)
		cfg->dead = 1;
	pthread_mutex_unlock(&cfg->dead_mutex);
	return (all_ate);
}

static int	check_philosophers_death(t_philo *philos, t_config *cfg)
{
	int	i;

	i = -1;
	while (++i < cfg->num_philos)
	{
		if (check_philosopher_status(&philos[i], cfg))
		{
			usleep(1000);
			return (1);
		}
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
		if (check_philosophers_death(philos, cfg))
			return (NULL);
		if (check_philosophers_meals(philos, cfg))
			return (NULL);
		usleep(100);
	}
	return (NULL);
}
