/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 18:06:42 by dinguyen          #+#    #+#             */
/*   Updated: 2025/02/04 14:40:38 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	create_threads(t_philo *philos, t_config *cfg)
{
	int	i;

	i = 0;
	while (i < cfg->num_philos)
	{
		if (pthread_create(&philos[i].thread, NULL,
				&philo_routine, &philos[i]) != 0)
		{
			while (--i >= 0)
				pthread_join(philos[i].thread, NULL);
			return (ERROR);
		}
		i++;
	}
	return (SUCCESS);
}

static void	init_philo(t_philo *philo, int i, t_config *cfg, t_fork *forks)
{
	philo->id = i;
	philo->meals_eaten = 0;
	philo->last_meal = 0;
	philo->config = cfg;
	philo->w_mutex = &cfg->write_mutex;
	philo->is_eating = 0;
	philo->l_fork = &forks[i];
	if (i == cfg->num_philos - 1)
		philo->r_fork = &forks[0];
	else
		philo->r_fork = &forks[i + 1];
}

int	init_all(t_config *cfg, t_philo **philos)
{
	t_fork	*forks;
	int		i;

	*philos = malloc(sizeof(t_philo) * cfg->num_philos);
	forks = malloc(sizeof(t_fork) * cfg->num_philos);
	if (!*philos || !forks)
		return (ERROR);
	i = 0;
	while (i < cfg->num_philos)
	{
		if (pthread_mutex_init(&forks[i].mutex, NULL) != 0)
		{
			free(forks);
			free(*philos);
			return (ERROR);
		}
		forks[i].id = i;
		init_philo(&philos[0][i], i, cfg, forks);
		i++;
	}
	if (pthread_mutex_init(&cfg->dead_mutex, NULL) != 0
		|| pthread_mutex_init(&cfg->write_mutex, NULL) != 0)
		return (ERROR);
	return (SUCCESS);
}

void	cleanup(t_philo *philos, t_config *cfg)
{
	int	i;

	i = 0;
	while (i < cfg->num_philos)
	{
		pthread_mutex_destroy(&philos[i].l_fork->mutex);
		i++;
	}
	pthread_mutex_destroy(&cfg->dead_mutex);
	pthread_mutex_destroy(&cfg->write_mutex);
	free(philos[0].l_fork);
	free(philos);
}
