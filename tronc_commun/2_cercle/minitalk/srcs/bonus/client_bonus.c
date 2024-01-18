/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:22:07 by greg              #+#    #+#             */
/*   Updated: 2024/01/18 08:12:13 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/minitalk.h"

static void	valid_send(int i)
{
	static int bytes = 0;
	static int chars = 1;

	if ((i == SIGUSR1 && bytes % 7 != 0) || (i == SIGUSR1 && bytes == 0))
	{
		ft_printf("char %2d | Byte %3d | signal answer valide !\n", chars, bytes);
		bytes++;
	}
	else
	{
		ft_printf("char %2d | Byte %3d | signal answer valide !\n", chars, bytes);
		chars++;
		bytes = 0;
	}
}

/*int	main(int argc, char **argv)
{
	pid_t	pid;
	int		i;

	if (argc != 3)
		return (ft_printf("Invalid number of arguments !\nThe correct format is ./client pid array\n"), 0);
	pid = ft_atoi(argv[1]);
	if (pid == 0)
		return(ft_printf("Invalide pid !\n"), 0);
	i = 0;
	signal(SIGUSR1, valid_send);
	while (argv[2][i])
	{
		client_send_char(argv[2][i], pid);
		i++;
	}
	client_send_char('\0', pid);
	return (0);
}*/

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

//		wstr to str echapement		//

void wcharToEscapedString(const wchar_t *src, char *dst)
{
    while (*src != L'\0')
    {
        if (*src >= 32 && *src <= 126)
        {
            // Caractères ASCII normaux
            *dst = (char)(*src);
            ++dst;
        }
        else
        {
            // Caractères non-ASCII, convertis en séquences d'échappement Unicode
            *dst = '\\';
            ++dst;
            *dst = 'u';
            ++dst;
            // Conversion du caractère en séquence hexadécimale
            for (int shift = 12; shift >= 0; shift -= 4)
            {
                char hexDigit = (*src >> shift) & 0xF;
                *dst = hexDigit < 10 ? '0' + hexDigit : 'A' + (hexDigit - 10);
                ++dst;
            }
        }
        ++src;
    }
    *dst = '\0';
}
//		argv to wstr		//

void appendHex(wchar_t wc, char *dst)
{
    char hex[5];
    int i;

    for (i = 0; i < 4; ++i)
    {
        int digit = wc % 16;
        wc /= 16;

        if (digit < 10)
            hex[3 - i] = '0' + digit;
        else
            hex[3 - i] = 'A' + (digit - 10);
    }

    hex[4] = '\0';

    i = 0;
    while (hex[i] != '\0')
    {
        *dst = hex[i];
        ++dst;
        ++i;
    }
}

wchar_t *unitowstr(char *input)
{
    int i;
	int j;
	int k;
	int len;
	unsigned char uc;
	wchar_t wc;
	wchar_t	*ws;

	i = 0;
	j = 0;
	ws = malloc((ft_strlen(input) + 1) * sizeof(wchar_t));
    while (input[i] != '\0')
    {
        uc = (unsigned char)input[i];
        wc = 0;
        len = 0;
        if (uc < 0x80)
        {
            wc = uc;
            len = 1;
        }
        else if ((uc & 0xE0) == 0xC0)
        {
            wc = uc & 0x1F;
            len = 2;
        }
        else if ((uc & 0xF0) == 0xE0)
        {
            wc = uc & 0x0F;
            len = 3;
        }
        else if ((uc & 0xF8) == 0xF0)
        {
            wc = uc & 0x07;
            len = 4;
        }
		k = 1;
        while (k < len)
        {
            wc = wc << 6;
            wc |= (unsigned char)input[i + k] & 0x3F;
			k++;
        }
		ws[j] = wc;
		j++;
        i += len;
    }
	ws[j] = L'\0';
	return (ws);
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	int		i;
    setlocale(LC_ALL, "");
	wchar_t *ws;
    char dst[1024];

	if (argc != 3)
		return (ft_printf("Invalid number of arguments !\nThe correct format is ./client pid array\n"), 0);
	pid = ft_atoi(argv[1]);
	if (pid == 0)
		return(ft_printf("Invalide pid !\n"), 0);
	i = 0;
	signal(SIGUSR1, valid_send);
	ws = unitowstr(argv[2]);
	wprintf(L"wc = %ls\n", ws);
	wcharToEscapedString(ws, dst);
	ft_printf("Destination: %s\n", dst);
	while (dst[i])
	{
		client_send_char(dst[i], pid);
		i++;
	}
	client_send_char('\0', pid);
	return (0);
}
