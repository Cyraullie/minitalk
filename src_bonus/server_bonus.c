/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:50:36 by cgoldens          #+#    #+#             */
/*   Updated: 2024/11/19 13:51:07 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	handle_sigusr(int signum, siginfo_t *info, void *ucontent)
{
	static int				bit_itr = -1;
	static unsigned char	c;

	(void)ucontent;
	if (bit_itr < 0)
		bit_itr = 7;
	if (signum == SIGUSR1)
		c |= (1 << bit_itr);
	bit_itr--;
	if (bit_itr < 0 && c)
	{
		ft_putchar_fd(c, STDOUT_FILENO);
		c = 0;
		if (kill(info->si_pid, SIGUSR2) == -1)
			handle_errors("Server failed to send SIGUSR2");
		return ;
	}
	if (kill(info->si_pid, SIGUSR1) == -1)
		handle_errors("Failed to send SIGUSR1");
}

void	config_signals(void)
{
	struct sigaction	sa_newsig;

	sa_newsig.sa_sigaction = &handle_sigusr;
	sa_newsig.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa_newsig, NULL) == -1)
		handle_errors("Failed to change SIGUSR1's behavior");
	if (sigaction(SIGUSR2, &sa_newsig, NULL) == -1)
		handle_errors("Failed to change SIGUSR2's behavior");
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("SERVER PID = %d\n\n", pid);
	while (1)
		config_signals();
	return (EXIT_SUCCESS);
}
