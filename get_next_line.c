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
	char *str;
	int lec;

	lec = read(fd, shot, BUFF_SIZE);
	shot[lec] = '\0';
	bufr = ft_strjoin("", shot);
	if (bufr == "")
	{
		ft_strclr(bufr);
		return(NULL);
	}
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
	if(bufr == "")
		return NULL;
	while ((bufr[i]) && (bufr[i] != '\n'))
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

int 	breakchecks(char *str) // Returns 1 if break is needed, 0 if not
{
	unsigned long i;

	i = 0;
	if (str[i] == '\0')
		return (0);
	if (ft_strchr(str, '\n') != NULL)
		return (1);
	//if (ft_strlen(str) != BUFF_SIZE)
	//	return (1);
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

	*line = "";
	if (!line || fd < 0)
		return (-1);
	while (1)
	{
		if ((bufr[0] != '\0') && ((ft_strchr(bufr, '\n') == NULL) || breakchecks(bufr) == 0))
			*line = ft_strdup(ft_strjoin(*line, bufr));
		else if(breakchecks(bufr) == 1)
			break;
		if(bufr = readone(bufr, fd))
			if(ft_strlen(bufr) == 0)
				break;
		if (breakchecks(bufr) == 1)
			break;
		*line = ft_strdup(ft_strjoin(*line, bufr));
		ft_strclr(bufr);
	}
	*line = ft_strdup(ft_strjoin(*line, cut_end(bufr)));
	//save = ft_strjoin(save, cut_end(bufr));
	//*line = ft_strdup(save);
	bufr = after_line(bufr);
	return (1);
}
