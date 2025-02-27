/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 18:07:43 by dinguyen          #+#    #+#             */
/*   Updated: 2025/02/04 15:49:59 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	handle_single_philo(t_philo *p)
{
	pthread_mutex_lock(&p->l_fork->mutex);
	print_status(p, FORK_TAKEN);
	ft_usleep(p->config->t_to_die);
	pthread_mutex_unlock(&p->l_fork->mutex);
}

void	take_forks(t_philo *p)
{
	if (p->config->num_philos == 1)
	{
		handle_single_philo(p);
		return ;
	}
	if (p->id % 2 == 0)
		usleep(500);
	pthread_mutex_lock(&p->l_fork->mutex);
	print_status(p, FORK_TAKEN);
	pthread_mutex_lock(&p->r_fork->mutex);
	print_status(p, FORK_TAKEN);
}

static void	eat(t_philo *p)
{
	take_forks(p);
	pthread_mutex_lock(&p->config->dead_mutex);
	p->last_meal = get_current_time();
	p->is_eating = 1;
	p->meals_eaten++;
	pthread_mutex_unlock(&p->config->dead_mutex);
	print_status(p, EATING);
	ft_usleep(p->config->t_to_eat);
	p->is_eating = 0;
	pthread_mutex_unlock(&p->r_fork->mutex);
	pthread_mutex_unlock(&p->l_fork->mutex);
}

static void	philo_sleep(t_philo *p)
{
	print_status(p, SLEEPING);
	ft_usleep(p->config->t_to_sleep);
	print_status(p, THINKING);
}

void	*philo_routine(void *arg)
{
	t_philo	*p;

	p = (t_philo *)arg;
	p->last_meal = get_current_time();
	if (p->config->num_philos == 1)
	{
		handle_single_philo(p);
		return (NULL);
	}
	while (!p->config->dead)
	{
		eat(p);
		if (p->config->must_eat > 0
			&& p->meals_eaten >= p->config->must_eat)
			break ;
		philo_sleep(p);
	}
	return (NULL);
}
