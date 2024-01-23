/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:22:07 by greg              #+#    #+#             */
/*   Updated: 2024/01/23 08:27:28 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk.h"

static void	valid_send(int i)
{
	static int (bytes) = 0;
	static int (chars) = 1;
	if ((i == SIGUSR1 && bytes % 7 != 0) || (i == SIGUSR1 && bytes == 0))
	{
		ft_printf("char %2d | Byte %3d | answer valide !\n", chars, bytes);
		bytes++;
	}
	else
	{
		ft_printf("char %2d | Byte %3d | answer valide !\n", chars, bytes);
		chars++;
		bytes = 0;
	}
}

static wchar_t	*unitowstr(char *input)
{
	int				i;
	int				j;
	int				len;
	wchar_t			*ws;
	unsigned char	uc;

	ws = malloc((ft_strlen(input) + 1) * sizeof(wchar_t));
	if (!ws)
		return (0);
	i = 0;
	j = 0;
	while (input[i] != '\0')
	{
		uc = (unsigned char)input[i++];
		if (ft_is_ascii(uc))
			ws[j++] = asciitowc(uc);
		else if (ft_is_multi_byte(uc))
		{
			i--;
			len = ft_uclen(uc);
			ws[j++] = mbytowc(&input[i], len);
			i += len;
		}
	}
	return (ws[j] = L'\0', ws);
}

static void	wctoestr(const wchar_t *src, char *dst)
{
	int		shift;
	char	hexa_digit;

	while (*src != L'\0')
	{
		if (*src >= 32 && *src <= 126)
			*dst++ = (char)(*src);
		else
		{
			*dst++ = '\\';
			*dst++ = 'u';
			shift = 12;
			while (shift >= 0)
			{
				hexa_digit = (*src >> shift) & 0xF;
				if (hexa_digit < 10)
					*dst++ = '0' + hexa_digit;
				else
					*dst++ = 'A' + (hexa_digit - 10);
				shift -= 4;
			}
		}
		src++;
	}
	*dst = '\0';
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	int		i;
	wchar_t	*ws;
	char	dst[1024];

	setlocale(LC_ALL, "");
	if (argc != 3)
		return (ft_printf("The correct format is ./client pid array\n"), 0);
	pid = ft_atoi(argv[1]);
	if (pid == 0)
	{
		ft_printf("Invalide pid !\n");
		return (0);
	}
	i = 0;
	signal(SIGUSR1, valid_send);
	ws = unitowstr(argv[2]);
	wctoestr(ws, dst);
	while (dst[i])
	{
		client_send_char(dst[i], pid);
		i++;
	}
	client_send_char('\0', pid);
	return (0);
}
