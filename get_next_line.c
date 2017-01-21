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

// SCAN :D 
int 	ft_searchbak(char *bufr)
{
	if (ft_strchr(bufr, '\0'))
		return (2);
	else if (ft_strchr(bufr, '\n'))
		return (1);
	else
		return (0);
}

int 	after_cpy(char **line, char *bufr)
{
	// Do not forget to no copy \n.
	//read(fd, buf, BUFF_SIZE)
}

int 	detect_zero(char *bufr)
{
	// Simply detect a \0 to do a correct return .
}

int		get_next_line(const int fd, char **line)
{
	int 		stop;
	static char	bufr[BUF_SIZE + 1]; // Whole text before the last \n of the last exec
	char 		*str;

	stop = 1;
	if (fd < 0 || !line) // Validity check
		return (-1);
	while (stop) // While No EOF or \n... in reality
	{
		if (stop = read(fd, buf, BUFF_SIZE)) // Can't read anymore :(
			return (-1);
		if (ft_searchbak(bufr) == 0) // Is a baque here ? Case no baque.
		{
			// COPY CORRECTLY (\0, at the end , strjoin last string ...)
		}
		else if // BAQUE OR \0 INCOMING
		{	
				// COPY CORRECTLY (\0, at the end , strjoin last string ...)
				// But return pls
				stop = 0;
		}
		// clear buff ? (ft_strclr ? b_zero?)
	}
	if (stop == 0)
		return (1);
	return (1);
}