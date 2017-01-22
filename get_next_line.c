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

#include "gnl.h"

char* 	copy_case_zero(char *bufr, char *reader)
{
	int i;

	i = 0;
	// ALLOC PLS
	while (bufr[i] != '\0')
	{	
		bufr[ft_strlen(bufr) + 1] = reader[i];
		i++;
	}
	bufr[ft_strlen(bufr) + 1] = '\0';
	return (bufr);
}

char* 	copy_case_line(char *bufr, char *reader)
{
	// COPY CORRECTLY (ONLY strjoin last string ...)
	// DO NOT copy \n.
	// replace by \0

	// ALLOC PLS
	int i;

	i = 0;
	while (bufr[i] != '\n')
	{	
		bufr[ft_strlen(bufr) + 1] = reader[i];
		i++;
	}
	bufr[ft_strlen(bufr) + 1] = '\0';
	return (bufr);
}

char*	copy_case_normal(char *bufr, char *reader)
{
	// COPY CORRECTLY (ONLY strjoin last string ...)

	// ALLOC PLS
	ft_strjoin(bufr, reader);
}

int		get_next_line(const int fd, char **line)
{
	static char	bufr[BUFF_SIZE + 1]; // Whole text before the last \n of the last exec
	char 		*reader;

	while (1) // While we are not at the EOF/\n.
	{
		if (!(reader = read(fd, buf, BUFF_SIZE))) // Can't read anymore :(
			return (-1);
		if (fd < 0 || !line || reader[0] == '\0') // Validity check
			return (-1);
		if (ft_strchr(reader, '\0')) // Case Zero.
		{	
			bufr = copy_case_zero(bufr, reader)
			return (0);
		}
		else if (ft_strchr(reader, '\n')) // Case line.
		{	
			bufr = copy_case_line(bufr, reader)
			return (1);
		}
		else //Case nothing.
		{
			copy_case_normal()
		}
	}	
}