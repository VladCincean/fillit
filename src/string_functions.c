#include "fillit.h"
#include <unistd.h>

void	*ft_memset(void *s, int c, unsigned int n)
{
	unsigned char	*ptr;
	unsigned int	i;

	if (!s)
		return (0);
	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
		ptr[i++] = (unsigned char)c;
	return (s);
}

void	ft_putstr(char *s)
{
	write(1, s, ft_strlen(s));
}

int		ft_strlen(char *s)
{
	int	l;

	l = 0;
	while (*s++)
		l++;
	return (l);
}
