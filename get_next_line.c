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

/*char* 	copy_case_zero(char *bufr, char *reader)
{
	int i;

	i = 0;
	while (bufr[i] != '\0')
		i++;
	if (!(bufr = (char *)malloc(ft_strlen(bufr) + i + 1)))
		return (NULL);
	while (reader[i])
	{
		bufr[ft_strlen(bufr) + 1] = reader[i];
		i++;
	}
	bufr[ft_strlen(bufr) + 1] = '\0';
	return (bufr);
}

char* 	copy_case_line(char *bufr, char *reader)
{
	int i;

	i = 0;
	while (bufr[i] != '\n')
		i++;
	if (!(bufr = (char *)malloc(ft_strlen(bufr) + i + 1)))
		return (NULL);
	while (reader[i] != '\n')
	{	
		bufr[ft_strlen(bufr) + 1] = reader[i];
		i++;
	}
	bufr[ft_strlen(bufr) + 1] = '\0';
	return (bufr);
}

char*	copy_case_normal(char *bufr, char *reader)
{
	int i;

	i = 0;
	if (!(bufr = (char *)malloc(ft_strlen(bufr) + ft_strlen(reader))))
		return (NULL);
	while (reader[i] != '\0')
	{	
		bufr[ft_strlen(bufr) + 1] = reader[i];
		i++;
	}
	bufr[ft_strlen(bufr) + 1] = '\0';
	return (bufr);
}*/

int		get_next_line(const int fd, char **line)
{
	static char	bufr[BUFF_SIZE + 1]; // Whole text before the last \n of the last exec
	char 		*buf; // Buffer
	int 		ret; // Stop
	//char *reader;

	while ((ret = read(fd, buf, BUFF_SIZE))) // While we are not at the EOF/\n.
	{
		if (fd < 0 || !line || buf[0] == '\0') // Validity check
			return (-1);
		//if (!(ret = (char *)malloc(BUFF_SIZE + 1 * sizeof(char))))
		//	return (-2);
		//ft_strcpy(reader,buf);
		//printf("Le reader : %s \n", reader);
		printf("Le buf : %s \n", buf);
		if (ft_strchr(buf, '\0')) // Case Zero.
		{	
			printf("Including zero ");
			//bufr = copy_case_zero(bufr, reader);
			//return (0);
		}
		if (ft_strchr(buf, '\n')) // Case line.
		{	
			printf("Including baque");
			//bufr = copy_case_line(bufr, reader);
			//return (1);
		}
		else //Case nothing.
			//bufr = copy_case_normal(bufr, reader);
			printf("noting");
	}
	return (1);	
}