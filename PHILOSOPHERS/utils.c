/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:00:51 by dinguyen          #+#    #+#             */
/*   Updated: 2025/02/02 20:29:27 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*
struct timeval
{
	time_t		tv_sec;		// Nombre de SECONDES depuis 1970
	suseconds_t	tv_usec;	// Nombre de MICROSECONDES
}
*/
long long	get_current_time(void)
{
	struct timeval	current_time;
	long long		seconds;
	long long		microseconds;
	long long		milliseconds;

	gettimeofday(&current_time, NULL);
	seconds = current_time.tv_sec;
	seconds = seconds * 1000;
	microseconds = current_time.tv_usec;
	microseconds = microseconds / 1000;
	milliseconds = seconds + microseconds;
	return (milliseconds);
}

int	ft_is_number(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	long	result;
	int		i;

	result = 0;
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		if (result > INT_MAX)
			return (-1);
		i++;
	}
	return ((int)result);
}

static int	is_died(const char *status)
{
	int		i;
	char	*d;

	d = "died";
	i = 0;
	while (status[i] && d[i] && status[i] == d[i])
		i++;
	if (!status[i] && !d[i])
		return (1);
	return (0);
}

void	print_status(t_philo *philo, char *status)
{
	long long	current_time;

	pthread_mutex_lock(philo->w_mutex);
	current_time = get_current_time() - philo->config->start_time;
	if (!philo->config->dead || is_died(status))
	{
		printf("%lld %d %s\n", current_time, philo->id + 1, status);
	}
	pthread_mutex_unlock(philo->w_mutex);
}
