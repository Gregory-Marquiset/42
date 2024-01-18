
#include "includes/headers/minitalk.h"
#include <stdio.h>

//		from argv with unicode to str d'echapement		//

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
	int shift;
	char hexDigit;

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
                hexDigit = (*src >> shift) & 0xF;
                *dst = hexDigit < 10 ? '0' + hexDigit : 'A' + (hexDigit - 10);
                dst++;
				shift -= 4;
            }
        }
        src++;
    }
    *dst = '\0';
}

//		argv to wstr		//

void appendHex(wchar_t wc, char *dst)
{
    char hex[5];
    int i;
	int digit;

	i = 0;
    while (i < 4)
    {
        digit = wc % 16;
        wc /= 16;
        if (digit < 10)
            hex[3 - i] = '0' + digit;
        else
            hex[3 - i] = 'A' + (digit - 10);
			i++;
    }
    hex[4] = '\0';
    i = 0;
    while (hex[i] != '\0')
        *dst++ = hex[i++];
}


int isASCII(unsigned char c)
{
    return c < 0x80;
}

int isMultiByteStart(unsigned char c)
{
	return ((c & 0xE0) == 0xC0 || (c & 0xF0) == 0xE0 || (c & 0xF8) == 0xF0);
}

wchar_t convertASCIIToWchar(unsigned char c)
{
	return (c);
}

wchar_t convertMultiByteToWchar(const char *input, int len)
{
	wchar_t	wc;
	int	i;

	wc = (unsigned char)input[0] & (0xFF >> (len + 1));
	i = 1;
	while (i < len)
	{
		wc = wc << 6;
		wc |= (unsigned char)input[i] & 0x3F;
		i++;
	}
	return (wc);
}

wchar_t *unitowstr(char *input)
{
    int i = 0;
    int j = 0;
    int len;
    wchar_t *ws;

    ws = malloc((ft_strlen(input) + 1) * sizeof(wchar_t));
    if (!ws)
        return NULL;
    while (input[i] != '\0')
    {
        unsigned char uc = (unsigned char)input[i];
		i++;
        if (isASCII(uc))
            ws[j++] = convertASCIIToWchar(uc);
        else if (isMultiByteStart(uc))
        {
			i--;
            len = uc < 0xE0 ? 2 : (uc < 0xF0 ? 3 : 4);
            ws[j++] = convertMultiByteToWchar(&input[i], len);
            i += len;
        }
    }
    ws[j] = L'\0';
    return (ws);
}

int main(int argc, char **argv)
{
    setlocale(LC_ALL, "");
	wchar_t *ws;
    char dst[1024];

    if (argc == 2)
	{
        ws = unitowstr(argv[1]);
		wprintf(L"wc = %ls\n", ws);
		wcharToEscapedString(ws, dst);
		ft_printf("dst: %s\n", dst);
	}
    return 0;
}
