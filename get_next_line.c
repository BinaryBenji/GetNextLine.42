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

char	*readone(char *bufr, int fd) // Reads BUFF_SIZE characters. Returns NULL if
{
	char shot[BUFF_SIZE + 1];
	int lec;

	lec = read(fd, shot, BUFF_SIZE);
	shot[lec] = '\0';
	bufr = ft_strjoin("", shot);
	if (lec == 0) 
	{
		ft_bzero(shot, BUFF_SIZE + 1);
		ft_strclr(bufr);
		return(NULL);
	}
	ft_bzero(shot, BUFF_SIZE + 1);
	return (bufr);
}

char	*handle_end(char *bufr, int choice) // Cuts the end of the line, when a \n is in the bufr variable
{
	int		i;
	char	*str;
	int j;

	j = 0;
	i = 0;
	while ((bufr[i]) && (bufr[i] != '\n'))
		i++;
	if (choice == 1) // cut end
	{
		str = ft_strnew(i);
		while ((bufr[j]) && (bufr[j] != '\n'))
		{
			str[j] = bufr[j];
			j++;
		}
		str[j] = '\0';
		return (str);
	}
	i++;
	str = ft_strnew(ft_strlen(bufr) - i + 1);
	while (bufr[i])
		str[j++] = bufr[i++];
	str[j] = '\0';
	return (str);
}

int 	breakchecks(char *str) // Returns 1 if break is needed, 0 if not
{
	unsigned long i;

	i = 0;
	if (str[i] == '\0')
		return (0);
	if (ft_strchr(str, '\n') != NULL)
		return (1);
	while(i < BUFF_SIZE)
	{
		if (str[i] == '\0')
			return (1);
		i++;
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static char	*bufr = "\0";

	if (!line || fd < 0)
		return (-1);
	*line = "";
	while (1)
	{
		if ((bufr != NULL) && (bufr[0] != '\0') &&
		 ((ft_strchr(bufr, '\n') == NULL) || breakchecks(bufr) == 0))
			*line = ft_strdup(ft_strjoin(*line, bufr));
		else if((bufr != NULL) && (breakchecks(bufr) == 1))
			break;
		if((bufr = readone(bufr, fd)) == NULL)
			return (0);
		if (breakchecks(bufr) == 1)
			break;
		*line = ft_strdup(ft_strjoin(*line, bufr));
		ft_strclr(bufr);
	}
	*line = ft_strdup(ft_strjoin(*line, handle_end(bufr,1)));
	bufr = handle_end(bufr,0);
	return (1);
}
