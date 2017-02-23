/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzmuda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 15:23:25 by bzmuda            #+#    #+#             */
/*   Updated: 2017/02/23 14:02:26 by bzmuda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*readone(char *bufr, int fd)
{
	char shot[BUFF_SIZE + 1];

	ft_strclr(bufr);
	if(read(fd, shot, BUFF_SIZE) == -1)
		return(NULL);
	shot[BUFF_SIZE] = '\0';
	bufr = ft_strdup(shot);
	return (bufr);
}

char	*cut_end(char *bufr)
{
	int		i;
	char	*tosave;

	i = 0;
	while ((bufr[i]) && (bufr[i] != '\n'))
		i++;
	if (!(tosave = (char *)malloc((i + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while ((bufr[i]) && (bufr[i] != '\n'))
	{
		tosave[i] = bufr[i];
		i++;
	}
	tosave[i] = '\0';
	return (tosave);
}

char	*after_line(char *bufr)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (bufr[i] != '\n')
		i++;
	if (!(str = (char *)malloc(BUFF_SIZE - i + 1 * sizeof(char))))
		return (NULL);
	i++;
	while ((bufr[i]) && (i < BUFF_SIZE))
	{
		str[j] = bufr[i];
		j++;
		i++;
	}
	str[j] = '\0';
	return (str);
}

int 	check_end(char *bufr)
{
	unsigned long i;

	i = 0;
	if (bufr[i] == '\0')
		return (0);  
	while(i < ft_strlen(bufr) - 1)
	{
		if(bufr[i] == '\0')
			return (1);
		i++;
	}
	return(0);
}

int		get_next_line(const int fd, char **line)
{
	static char	*bufr = "\0";
	char		*save;
	char 		*end;

	save = ft_memalloc(1);
	if (!line || fd < 0)
		return (-1);
	while (1)
	{
		if ((ft_strchr(bufr, '\n') != NULL) || (check_end(bufr) == 1))
			break ;
		save = ft_strjoin(save, bufr);
		*line = ft_strdup(save);
		bufr = readone(bufr, fd);
	}
	end = cut_end(bufr);
	save = ft_strjoin(save, end);
	*line = ft_strdup(save);
	if (ft_strchr(bufr, '\n') != NULL)
	{
		bufr = after_line(bufr);
		return (1);
	}
	return (0);
}
