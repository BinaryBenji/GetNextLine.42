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

int 	ft_precise_scan(char *str)
{	
	// READ STR 

	// RETURN POSITION OF THE \n or EOF 
}

int 	ft_scan(char *str)
{
	// SCANNER EOF AND \n

	// RETURN 1 for presence
	// 0 FOR ABSENCE
}

int		get_next_line(const int fd, char **line)
{
	int		fd;
	int		byte_read;
	char	buf[BUF_SIZE];
	char 	*str;

	byte_read = 0;
	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		return (-1);
	else
	{
		*str = ft_strnew(0);
		while ((byte_read = read(fd, buf, BUF_SIZE)) > 0) // tant qu on est pas arrive a EOF
		{

			// Doit bouffer un coup de buffer
			// Scanner ce qu'il a bouffe
			// Si le scanner return 0
				// OKLM on stocke (sans le '\0' ?)
			// sinon
				// GO PRECISE_SCAN pour trouver la ou s'arreter
				// stocker ce qu'il faut
				// MAIS RETURN 1


			//buf[byte_read] = '\0';
			//*str = ft_strjoin(*str, buf);
		}
		//close(fd);
		if (byte_read == -1)
			return (error());
	}
	return (0);



}
