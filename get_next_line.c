/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzmuda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 15:23:25 by bzmuda            #+#    #+#             */
/*   Updated: 2017/02/28 16:23:44 by bzmuda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
**	Joins 2 strings into a new string. Free the s* lines if needed
*/

char	*ft_strjoin_free(char *s1, char *s2, int freez1, int freez2)
{
	char	*s;
	int		i;
	int		j;

	if (!s1 || !s2 || (!(s = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		s[i] = s1[i];
		i++;
	}
	j = i;
	i = 0;
	while (s2[i] != '\0')
	{
		s[j] = s2[i];
		j++;
		i++;
	}
	s[j] = '\0';
	(freez1 > 0) ? ft_strdel(&s1) : NULL;
	(freez2 > 0) ? ft_strdel(&s2) : NULL;
	return (s);
}

/*
**	Reads BUFF_SIZE characters.
**	Returns NULL if there are no more characters to read
*/

char	*readone(char *bufr, int fd)
{
	char	shot[BUFF_SIZE + 1];
	int		lec;

	lec = read(fd, shot, BUFF_SIZE);
	shot[lec] = '\0';
	if (lec == 0)
	{
		ft_strclr(bufr);
		return (NULL);
	}
	bufr = ft_strjoin_free("", shot, 0, 0);
	return (bufr);
}

/*
**	Cuts the end of the line, when a \n is in the bufr variable
*/

char	*handle_end(char *bufr, int choice)
{
	int		i;
	char	*str;
	int		j;

	j = 0;
	i = 0;
	while ((bufr[i]) && (bufr[i] != '\n'))
		i++;
	if (choice == 1)
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
	free(bufr);
	return (str);
}

/*
**	Returns 1 if break is needed, 0 if not
*/

int		breakchecks(char *str)
{
	unsigned long i;

	i = 0;
	if (str[i] == '\0')
		return (0);
	if (ft_strchr(str, '\n') != NULL)
		return (1);
	while (i < BUFF_SIZE)
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

	if (fd < 0 || !line || read(fd, bufr, 0) == -1)
		return (-1);
	*line = ft_strnew(1);
	while (1)
	{
		if ((bufr != NULL) && (bufr[0] != '\0') &&
			((ft_strchr(bufr, '\n') == NULL) || breakchecks(bufr) == 0))
			*line = ft_strjoin_free(*line, bufr, 1, 0);
		else if ((bufr != NULL) && (breakchecks(bufr) == 1))
			break ;
		if ((bufr = readone(bufr, fd)) == NULL)
			return (0);
		if (breakchecks(bufr) == 1)
			break ;
		*line = ft_strjoin_free(*line, bufr, 1, 0);
		bufr = "\0";
	}
	*line = ft_strjoin_free(*line, handle_end(bufr, 1), 1, 0);
	bufr = handle_end(bufr, 0);
	return (1);
}