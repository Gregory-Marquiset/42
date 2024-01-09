/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greg <greg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:34:43 by greg              #+#    #+#             */
/*   Updated: 2024/01/08 20:26:17 by greg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/minitalk.h"

static void	print_and_answer(int received, siginfo_t *si, void *ucontext)
{
	(void)ucontext;
	bytoc(received);
	kill(si->si_pid, SIGUSR1);
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	pid_t	pid;

	if (argc > 1 || argv[1])
		return (ft_printf("Too many arguments !\n"), 0);
	pid = getpid();
	ft_printf("The pid of this server is %d\n", pid);
	sa.sa_sigaction = &print_and_answer;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR2, &sa, NULL);
	sigaction(SIGUSR1, &sa, NULL);
	while (117)
		;
	return (0);
}
