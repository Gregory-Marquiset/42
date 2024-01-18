/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:34:43 by greg              #+#    #+#             */
/*   Updated: 2024/01/18 11:21:30 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/minitalk.h"

static void	ctoa_b(char c)
{
	static char	*str;
	static int	new_str = 0;

	if (new_str == 0)
	{
		str = malloc(2);
		str[0] = c;
		str[1] = '\0';
		new_str = 1;
	}
	else if (c >= 32 && c <= 126)
		str = ft_memcpy(str, c);
	else if (c == '\0')
	{
		strto(str);
		new_str = 0;
	}
}

static void	bytoc_b(int received)
{
	static int	i = 0;
	static char	c = 0;

	if (received == SIGUSR2)
		c += 1 << (7 - i);
	i++;
	if (i == 8)
	{
		ctoa_b(c);
		i = 0;
		c = 0;
	}
}

static void	print_and_answer(int received, siginfo_t *si, void *ucontext)
{
	(void)ucontext;
	bytoc_b(received);
	kill(si->si_pid, SIGUSR1);
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	pid_t				pid;

	setlocale(LC_ALL, "");
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
