#include "../../hdrs/libft.h"

static void	rf_joinstr(char **s1, char *s2)
{
	char	*temp;

	if (!*s1)
	{
		*s1 = ft_strdup(s2);
		return ;
	}
	temp = ft_strjoin(*s1, s2);
	ft_strdel(s1);
	*s1 = temp;
}

char		*ft_readfile(int fd)
{
	char	*rs;
	char	*buf;
	size_t	count;

	if (fd < 0)
		return (NULL);
	count = 64;
	buf = ft_strnew(count);
	rs = NULL;
	while (read(fd, buf, count))
	{
		rf_joinstr(&rs, buf);
		ft_bzero(buf, sizeof(buf));
	}
	return (rs);
}