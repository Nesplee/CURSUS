/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 18:26:38 by dinguyen          #+#    #+#             */
/*   Updated: 2025/02/02 20:29:13 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	check_philo_death(t_philo *p)
{
	long long	now;

	now = get_current_time();
	if ((now - p->last_meal) > p->config->t_to_die)
	{
		pthread_mutex_lock(&p->config->dead_mutex);
		if (!p->config->dead)
		{
			p->config->dead = 1;
			pthread_mutex_unlock(&p->config->dead_mutex);
			print_status(p, DIED);
			return (1);
		}
		pthread_mutex_unlock(&p->config->dead_mutex);
	}
	return (0);
}

static int	check_all_ate_enough(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos->config->num_philos)
	{
		if (philos[i].meals_eaten < philos->config->must_eat)
			return (0);
		i++;
	}
	return (1);
}

static int	check_end_conditions(t_philo *philos, t_config *cfg)
{
	if (cfg->dead)
		return (1);
	if (cfg->must_eat > 0 && check_all_ate_enough(philos))
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
	int			i;

	philos = (t_philo *)arg;
	cfg = philos[0].config;
	while (!cfg->dead)
	{
		i = 0;
		while (i < cfg->num_philos && !cfg->dead)
		{
			if (check_philo_death(&philos[i]))
				break ;
			i++;
		}
		if (check_end_conditions(philos, cfg))
			break ;
		usleep(100);
	}
	return (NULL);
}
