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

char 	*readone(char *bufr, int fd)
{
	char shot[BUFF_SIZE + 1];

	ft_strclr(bufr);
	read(fd, shot, BUFF_SIZE);
	shot[BUFF_SIZE] = '\0';
	ft_strcpy(bufr, shot);
	return (bufr);
}	

char 	*cut_end(char *bufr)
{
	int i;
	char *tosave;

	i = 0;
	while(bufr[i] != '\n')
		i++;
	if(!(tosave = (char *)malloc((i + 1)* sizeof(char))))
		return NULL;
	i = 0;
	while(bufr[i] != '\n')
	{
		tosave[i] = bufr[i];
		i++;
	}
	tosave[i] = '\0';
	return (tosave);
}

char 	*after_line(char *bufr)
{
	int i;
	int j;
	char *str;

	i = 0;
	j = 0;
	while(bufr[i] != '\n')
		i++;
	//ft_strclr(bufr);
	if(!(str = (char *)malloc(BUFF_SIZE - i + 1 * sizeof(char))))
		return NULL;
	i++;
	while(i < BUFF_SIZE)
	{
		str[j] = bufr[i];
		j++;
		i++;
	}
	str[j] = '\0';
	return(str);
}

int		get_next_line(const int fd, char **line)
{
	static char	*bufr;
	char 		*save; // Saver --> will be pasted in line
	char		*end;

	if (!line || fd < 0)
		return (-1);
	while (1)
	{
		if (!bufr)
			bufr = ft_memalloc(1);
		if (!save)
			save = ft_memalloc(1);
		save = ft_strjoin(save, bufr);
		if ((ft_strchr(bufr, '\n') == NULL) && (bufr[0] != '\0')) // Case no line.
		{
			*line = ft_strdup(save);
			ft_strclr(bufr);
		}
		if (!(bufr == readone(bufr, fd)))
			return (-1);
		if (ft_strchr(bufr, '\n') != NULL) // Break if line
			break;
	}
	end = cut_end(bufr);
	bufr = after_line(bufr);
	save = ft_strjoin(save, end);
	*line = ft_strdup(save);
	return (0);	
}