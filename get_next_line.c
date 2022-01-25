/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmolina <lmolina@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 21:37:59 by lmolina           #+#    #+#             */
/*   Updated: 2022/01/25 21:10:58 by lmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

#include <stdio.h>

void	ft_freestr(char **s)
{
	if (!s || !*s)
		return ;
	free(*s);
	*s = 0;
	return ;
}

char	*ft_slash_en(char **read)
{
	int		lenght;
	char	*line;
	char	*tmp;

	lenght = (ft_strchr(*read, '\n')) - *read;
	line = ft_strdup_n ((char *)*read, (lenght + 1));
	tmp = (char *)*read;
	*read = ft_strdup ((char *)&read[lenght + 1]);
	ft_freestr (&tmp);
	return (line);
}

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	static char	*readed;
	char		*line;
	char		*tmp;
	int			rl[2];

	rl[0] = 1;
	if ((BUFFER_SIZE < 1) || (read(fd, 0, 0)) || fd > 2048)
		return (0);
	while (rl[0] > 0)
	{	
		if (readed && (ft_strchr(readed, '\n')))
		{
			// rl[1] = (char *)(ft_strchr(readed, '\n')) - (char *)readed;
			// line = ft_strdup_n (readed, (rl[1] + 1));
			// tmp = readed;
			// readed = ft_strdup (&(readed[rl[1] + 1]));
			// ft_freestr (&tmp);
			line = ft_slash_en (&readed);
			return (line);
		}
		rl[0] = read(fd, buf, BUFFER_SIZE);
		buf[rl[0]] = '\0';
		if (rl[0] < 1 && (readed == '\0' || *readed == 0))
		{
			ft_freestr (&readed);
			return (0);
		}
		else if (rl[0] < 1 && readed != 0)
		{
			line = ft_strdup_n (readed, ft_strlen(readed));
			ft_freestr (&readed);
			return (line);
		}
		tmp = readed;
		if (!readed)
			readed = ft_strdup_n (buf, rl[0]);
		else
			readed = ft_strjoin (readed, buf);
		ft_freestr (&tmp);
	}
	return (0);
}

/*
int main (void)
{
	char *line;
	//char *line2;
	int fd;
	
	//fd = open("test2.txt", O_RDONLY);
	fd = open("./gnlTester/files/multiple_nlx5", O_RDONLY);
	//printf("Tyt 1\n");
	//printf("\n fd = %d\n", fd);
	//line = 
	

	line = get_next_line(fd);
	printf("at1 %s", line);
	line = get_next_line(fd);
	printf("at2 %s", line);
	line = get_next_line(fd);
	printf("at3 %s", line);
	line = get_next_line(fd);
	printf("at4 %s", line);
	line = get_next_line(fd);
	printf("at5 %s", line);
	line = get_next_line(fd);
	printf("at6 %s", line);
	line = get_next_line(fd);
	printf("at7 %s", line);
	line = get_next_line(fd);
	printf("at8 %s", line);
	line = get_next_line(fd);
	printf("at9 %s", line);
	line = get_next_line(fd);
	printf("at10 %s", line);
	line = get_next_line(fd);
	printf("at11 %s", line);
	line = get_next_line(fd);
	printf("at12 %s", line);
	
	//while (1) { continue; }
	//getchar();
	close (fd);
	//ft_freestr(&line);
}
*/