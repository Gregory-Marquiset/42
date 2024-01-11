
#include "includes/headers/minitalk.h"
#include <locale.h>
#include <stdio.h>
#include <wchar.h>

int	ft_wa_len(wchar_t	*wa)
{
	int	i;

	i = 0;
	while (wa[i])
		i++;
	return (i);
}

wchar_t	*ft_memwcpy(wchar_t *wa, wchar_t wc)
{
	int		len;
	wchar_t	*new;
	int		i;

	len = ft_wa_len(wa) + 2;
	new = malloc(len * sizeof(wchar_t));
	if (!new)
		return (0);
	i = 0;
	while (wa[i])
	{
		new[i] = wa[i];
		i++;
	}
	new[i] = wc;
	i++;
	new[i] = '\0';
	free(wa);
	return (new);
}

void	wctowa(wchar_t wc)
{
	static wchar_t	*wa;
	static int	new_wa = 0;

	if (new_wa == 0)
	{
		wa = malloc(2);
		wa[0] = wc;
		wa[1] = '\0';
		new_wa = 1;
	}
	else if (wc > '\0')
		wa = ft_memwcpy(wa, wc);
	else if (wc == '\0')
	{
		wprintf(L"%ls", wa);
		new_wa = 0;
		free(wa);
	}
}

void	bytowc(int	byte)
{
	static wchar_t	wc = L'\0';
	static int	i = 0;

	if (byte == 1)
		wc += 1 << (31 - i);
	i++;
	if (i == 32)
	{
		wctowa(wc);
		i = 0;
		wc = L'\0';
	}
}

int	main(void)
{
	int	i;
	int	j;
	int	byte;

	wchar_t	*wc = L"a et 😀";
	setlocale(LC_ALL, "");
	j = 0;
	while (wc[j])
	{
		i = sizeof(wchar_t) * 8 - 1;
		while (i >= 0)
		{
			byte = (wc[j] >> i) & 1;
			bytowc(byte);
			i--;
		}
	j++;
	}
	i = sizeof(wchar_t) * 8 - 1;
	while (i >= 0)
	{
		byte = (wc[j] >> i) & 1;
		bytowc(byte);
		i--;
	}
	wprintf(L"\n");
	return (0);
}
