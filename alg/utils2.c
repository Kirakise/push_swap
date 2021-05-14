#include "header.h"

size_t		ft_strlen(const char *s)
{
	size_t					i;
	const unsigned char		*s1;

	s1 = (const unsigned char *)s;
	i = 0;
	while (*s1++)
		i++;
	return (i);
}

int checknums(int *a, int zeroflag)
{
    int i;
    int j;

    i = 0;
    while (a[i])
    {
        j = i + 1;
        while (a[j])
        {
            if (a[i] == 1 && a[j] == 1 && zeroflag)
            {
                zeroflag = 0;
                j++;
            }
            else if (a[i] == a[j])
                return (1);
            else
                j++;
        }
        i++;
    }
    return (0);
}