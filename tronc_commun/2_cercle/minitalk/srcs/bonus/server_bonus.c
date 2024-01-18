/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:34:43 by greg              #+#    #+#             */
/*   Updated: 2024/01/18 04:35:10 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/minitalk.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int ft_wctobu_110000(char *s, wchar_t wc)
{
	if (!s)
		return 0;
	s[0] = (char)(0xF0 | (wc >> 18));
	s[1] = (char)(0x80 | ((wc >> 12) & 0x3F));
	s[2] = (char)(0x80 | ((wc >> 6) & 0x3F));
	s[3] = (char)(0x80 | (wc & 0x3F));
	return (4);
}

int ft_wctobu_10000(char *s, wchar_t wc)
{
	if (!s)
		return 0;
	s[0] = (char)(0xE0 | (wc >> 12));
	s[1] = (char)(0x80 | ((wc >> 6) & 0x3F));
	s[2] = (char)(0x80 | (wc & 0x3F));
	return (3);
}

int ft_wctobu_800(char *s, wchar_t wc)
{
	if (!s)
		return 0;
	s[0] = (char)(0xC0 | (wc >> 6));
	s[1] = (char)(0x80 | (wc & 0x3F));
	return (2);
}

int ft_wctobu_80(char *s, wchar_t wc)
{
	if (!s)
		return 0;
	*s = (char)wc;
	return (1);
}

		//		putstr/puchar but for wchar_t		//

void ft_putwchar(wchar_t wc)
{
	char	buffer[4];
	int		len;

	len = 0;
	if (wc < 0x80)
		len = ft_wctobu_80(buffer, wc);
	else if (wc < 0x800)
		len = ft_wctobu_800(buffer, wc);
	else if (wc < 0x10000)
		len = ft_wctobu_10000(buffer, wc);
	else if (wc < 0x110000)
		len = ft_wctobu_110000(buffer, wc);
	else
		len = -1;
	if (len > 0)
		write(1, buffer, len);
}

void ft_putwstr(wchar_t *wstr)
{
	int i;

	i = 0;
	while (wstr[i])
	{
		ft_putwchar(wstr[i]);
		i++;
	}
}
wchar_t	hexatowc(char *str)
{
	wchar_t	wc;
	int	i;
	int digit;

	wc = 0;
	i = 0;
	while (i < 4)
	{
		digit = str[i];
		if (digit >= '0' && digit <= '9')
			digit -= '0';
		else if (digit >= 'A' && digit <= 'F')
			digit -= 'A' - 10;
		else if (digit >= 'a' && digit <= 'f')
			digit -= 'a' - 10;
		wc = wc * 16 + digit;
		i++;
	}
	return (wc);
}

wchar_t *strtowstr(int len, char *str)
{
    int i;
    int j;
	wchar_t *wstr;

	wstr = malloc((len + 1) * sizeof(wchar_t));
	if (!wstr)
		return (0);
	i = 0;
	j = 0;
    while (i < len)
	{
		if (str[i] == '\\' && str[i + 1] == 'u')
		{
			i += 2;
			wstr[j++] = hexatowc(str + i);
			i += 4;
		}
		else
			wstr[j++] = (wchar_t)str[i++];
	}
	wstr[j] = L'\0';
	return (wstr);
}

int	ft_is_hexa(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else if (c >= 'a' && c <= 'f')
		return (1);
	else if (c >= 'A' && c <= 'F')
		return (1);
	return (0);
}

int	containe_unicode(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\\' && str[i + 1] == 'u')
		{
			i += 2;
			if (ft_is_hexa(str[i]) && ft_is_hexa(str[i + 1]) && ft_is_hexa(str[i + 2]) && ft_is_hexa(str[i + 3]))
				return (1);
		}
		i++;
	}
	return (0);
}

void strto(char *str)
{
    int len;
    wchar_t *wstr;

	if (!containe_unicode(str))
	{
		ft_printf("%s", str);
		free (str);
		return ;
	}
	else
	{
		len = ft_strlen(str);
		wstr = strtowstr(len, str);
		ft_putwstr(wstr);
		free(str);
		free (wstr);
	}
	return ;
}

char	*ft_memcpy(char *str, char c)
{
	int		len;
	char	*new;
	int		i;

	len = ft_strlen(str) + 2;
	new = malloc(len);
	if (!new)
		return (0);
	i = 0;
	while (str[i])
	{
		new[i] = str[i];
		i++;
	}
	new[i] = c;
	i++;
	new[i] = '\0';
	free(str);
	return (new);
}

void	ctoa_b(char c)
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

void	bytoc_b(int received)
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
	pid_t	pid;
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
