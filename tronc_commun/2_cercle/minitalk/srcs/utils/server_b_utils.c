/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_b_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 10:39:37 by gmarquis          #+#    #+#             */
/*   Updated: 2024/01/18 11:43:59 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/minitalk.h"

void	ft_putwchar(wchar_t wc)
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

void	ft_putwstr(wchar_t *wstr)
{
	int	i;

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
	int		i;
	int		digit;

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

wchar_t	*strtowstr(int len, char *str)
{
	int		i;
	int		j;
	wchar_t	*wstr;

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

void	strto(char *str)
{
	int		len;
	wchar_t	*wstr;

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
