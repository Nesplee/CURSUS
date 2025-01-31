/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:18:36 by dinguyen          #+#    #+#             */
/*   Updated: 2025/01/31 18:49:58 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <sys/time.h>

# define SUCCESS 0
# define ERROR 1
# define FORK_TAKEN "has taken a fork"
# define EATING "is eating"
# define SLEEPING "is sleeping"
# define THINKING "is thinking"
# define DIED "died"

typedef struct s_config
{
	int					num_philos;
	int					t_to_die;
	int					t_to_eat;
	int					t_to_sleep;
	int					must_eat;
	long long			start_time;
	pthread_mutex_t		dead_mutex;
	pthread_mutex_t		write_mutex;
	int					dead;
}	t_config;

typedef struct s_fork
{
	int				id;
	pthread_mutex_t	mutex;
}	t_fork;

typedef struct s_philo
{
	int				id;
	int				meals_eaten;
	long long		last_meal;
	pthread_t		thread;
	t_fork			*l_fork;
	t_fork			*r_fork;
	t_config		*config;
	pthread_mutex_t	*w_mutex;
	int				is_eating;
}	t_philo;

//	INIT
int			create_threads(t_philo *philos, t_config *cfg);
int			init_all(t_config *cfg, t_philo **philos);
void		cleanup(t_philo *philos, t_config *cfg);
//	MONITORING
void		*monitor_routine(void *arg);
int			check_death(t_philo *p);
//	PARSE
int			parse_args(int ac, char **av, t_config *cfg);
//	ROUTINE
void		*philo_routine(void *arg);
// UTILS
long long	get_current_time(void);
int			ft_is_number(char *str);
void		ft_usleep(long long time_to_wait);
int			ft_atoi(const char *str);
void		print_status(t_philo *philo, char *status);

#endif
