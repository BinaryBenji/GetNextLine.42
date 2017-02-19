/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzmuda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 15:23:25 by bzmuda            #+#    #+#             */
/*   Updated: 2017/01/17 15:24:10 by bzmuda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char 	**ft_realloc_case(char **line, int len, int choice)
{
	char *stock;
	int  lg;

	lg = ft_strlen(*line);
	if(!(stock = (char *)malloc(lg * sizeof(char) + 1)))
		return (NULL);
	ft_strcpy(stock, *line);
	stock[lg+1] = '\0';
	if (choice)
	{

		if(!(line = (char **)malloc((lg + len) * sizeof(char) + 1)))
			return NULL;
		ft_strcpy(*line, stock);
		return (&(*line));
	}
	else
	{
		if(!(line = (char **)malloc((lg + BUFF_SIZE) * sizeof(char) + 1)))
			return NULL;
		return (&(*line));
	}
} 

char 	*ft_strjoin_stop(char **line, char *buf) // 1 pour stop, 0 pour rien
{
	int i;
	char pico[BUFF_SIZE];
	int save;

	i = 0;
	while (buf[i] == '\n')
	{
		pico[i] = buf[i];
		i++;
	}
	line = ft_realloc_case(line, i, 1);
	save = i;
	i = 0;
	while (pico[i])
	{
		line[i] = &pico[i];
		i++;
	}
	return (*line);
}

int		get_next_line(const int fd, char **line)
{
	static char	bufr[BUFF_SIZE + 1];
	char 		*buf; // Buffer

	while (read(fd, buf, BUFF_SIZE))
	{
		if(bufr)
		{
			// Traiter le reste
		}
		if(!line)
			*line = ft_strnew(BUFF_SIZE);
		if (ft_strchr(buf, '\n') == 0) // Case no line.
		{
			if (line[0] != '\0')
				*line = *ft_realloc_case(line, BUFF_SIZE, 0);
			*line = ft_strjoin(*line, buf);
		}
		else  // Case line
		{
			*line = ft_strjoin_stop(line,buf);
			return(1);
		}
	}
	return (0);	
}